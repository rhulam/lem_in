#include "lem_in.h"

char    **file_array;

s_lem_in    *ft_copy(s_lem_in *list)
{
    s_lem_in    *copy;

    copy = malloc(sizeof(s_lem_in));
    copy->name = ft_strdup(list->name);
    copy->id = list->id;
    copy->x = list->x;
    copy->y = list->y;
    copy->start = list->start;
    copy->end = list->end;
    copy->length = list->length;
    copy->ant = 0;
    copy->next = list;
    copy->route = NULL;
    return copy;
}

int         add_route(s_lem_in *list, char *s1, char *s2)
{
    s_lem_in    *temp;
    s_lem_in    *first;
    s_lem_in    *second;

    temp = list;
    first = NULL;
    second = NULL;
    while (temp)
    {
        if (!ft_strcmp(temp->name, s1))
            first = temp;
        if (!ft_strcmp(temp->name, s2))
            second = temp;
        temp = temp->next;
    }
    free(s1);
    free(s2);
    if (!first || !second)
        return (0);
    temp = first;
    while (first->route)
    {
        if (first->route->id == second->id)
            return (1);
        first = first->route;
    }
    first->route = ft_copy(second);
    while (second->route)
        second = second->route;
    second->route = ft_copy(temp);
    return (1);
}

int         fill_routes(s_lem_in *first)
{
    int         i;
    int         j;
    int         k;
    char        *temp1;
    char        *temp2;

    i = 0;
    while (file_array[i])
    {
        if (valid_route(file_array[i]))
        {
            j = 0;
            k = 0;
            while (file_array[i][j] != '-')
                j++;
            temp1 = ft_strnew(j + 1);
            ft_strncpy(temp1, file_array[i], j);
            j++;
            while (file_array[i][j + k] != '\0')
                k++;
            temp2 = ft_strnew(k + 1);
            ft_strncpy(temp2, file_array[i] + j, k);
            if (!add_route(first, temp1, temp2))
                return (0);
        }
        i++;
    }
    return (1);
}

s_lem_in    *fill_vertex_list()
{
    int         i;
    s_lem_in    *list;
    s_lem_in    *first;
    int         id;

    i = 0;
    first = NULL;
    id = 1;
    while (file_array[i])
    {
        if (valid_numeric_line(file_array[i]))
        {
            if (!first)
            {
                first = create_vertex(file_array[i], id);
                list = first;
            }
            else
            {
                list->next = create_vertex(file_array[i], id);
                list = list->next;
            }
            if (!list)
            {
                free_list(first);
                return NULL;
            }
            id++;
            if (is_start(i - 1))
                list->start = 1;
            if (is_end(i - 1))
                list->end = 1;
        }
        i++;
    }
    return first;
}

void    fill_adjacency_list()
{
    s_lem_in    *list;
    s_lem_in    *temp;

    list = fill_vertex_list();
    if (!list)
        error();
    if (vertex_repeats(list))
        error();
    if (!fill_routes(list))
        error();
    list = start_to_first(list);
    create_routes(list, ft_atoi(file_array[0]));
}