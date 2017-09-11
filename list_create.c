#include "lem_in.h"

void    fill_vertex_list(s_lem_in *list, char **file_array)
{
    int     i;

    i = 0;
    while (file_array[i])
    {
        if (valid_numeric_line(file_array[i]))
            create_new_vertex(list, file_array[i]);
        if (is_start(file_array[i]))
        {
            list->start = 1;
            create_new_vertex(list, file_array[++i]);
        }
        if (is_end(file_array[i]))
        {
            list->end = 1;
            create_new_vertex(list, file_array[++i]);
        }
        if (list->next)
            list = list->next;
        i++;
    }
}

int     *find_id(s_lem_in *first_list, char *line)
{
    s_lem_in    *list;
    int         *id;
    int         i;
    char        *name;

    i = 0;
    id = malloc(sizeof(int) * 2);
    list = first_list;
    while (line[i] != '-')
        i++;
    name = ft_strnew(i);
    ft_strncpy(name, line, i);
    while (list)
    {
        if (list->name)
            if (!ft_strcmp(list->name, name))
            {
                id[0] = list->id;
                break;
            }
        list = list->next;
        if (!list)
        {
            free(name);
            return NULL;
        }
    }
    i++;
    free(name);
    name = ft_strnew(ft_strlen(line) - i);
    ft_strncpy(name, line + i, ft_strlen(line) - i);
    list = first_list;
    while (list)
    {
        if (list->name)
            if (!ft_strcmp(list->name, name))
            {
                id[1] = list->id;
                break;
            }
        list = list->next;
        if (!list)
        {
            free(name);
            return NULL;
        }
    }
    free(name);
    return (id);
}

int     fill_routes_array(int **routes_matrix, char **file_array, s_lem_in *first_list)
{
    int         i;
    int         *id;

    i = 0;
    while (file_array[i])
    {
        if (valid_route(file_array[i]))
        {
            if (!(id = find_id(first_list, file_array[i])))
                return 0;
            routes_matrix[id[0]][id[1]] = 1;
            routes_matrix[id[1]][id[0]] = 1;
        }
        i++;
    }
    if (double_vertexes(first_list))
        return (0);
    return (1);
}

int     count_vertexes(s_lem_in *first_list)
{
    s_lem_in    *list;

    list = first_list;
    while (list)
    {
        if (!((list->next)->next))
        {
            free(list->next);
            list->next = NULL;
            break;
        }
        list = list->next;
    }
    return (list->id);
}

void    fill_adjacency_list(char **file_array)
{
    s_lem_in    *list;
    s_lem_in    *first_list;
    int         **routes_matrix;
    int         i;
    int         n;
    int         j;

    i = 0;
    j = 0;
    list = malloc(sizeof(s_lem_in));
    list->next = NULL;
    list->id = 0;
    list->name = NULL;
    first_list = list;
    fill_vertex_list(list, file_array);
    n = count_vertexes(first_list) + 1;
    routes_matrix = malloc(sizeof(int*) * (n + 1));
    while (i < n)
    {
        routes_matrix[i] = malloc(sizeof(int) * (n + 1));
        while (j < n)
        {
            routes_matrix[i][j] = 0;
            j++;
        }
        j = 0;
        routes_matrix[i][n] = -1;
        i++;
    }
    routes_matrix[i] = NULL;
    if (!fill_routes_array(routes_matrix, file_array, first_list))
    {
        free_array(file_array);
        free_int_array(routes_matrix);
        free_list(first_list);
        error();
    }
    if (!create_routes(first_list, routes_matrix))
    {
        free_array(file_array);
        free_int_array(routes_matrix);
        free_list(first_list);
        error();
    }
}