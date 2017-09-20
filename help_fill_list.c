#include "lem_in.h"

char    **file_array;

s_lem_in    *start_to_first(s_lem_in *list)
{
    s_lem_in    *temp1;
    s_lem_in    *temp2;

    if (list->start)
        return list;
    temp1 = list;
    while (!temp1->next->start)
        temp1 = temp1->next;
    temp2 = temp1->next;
    temp1->next = temp1->next->next;
    temp2->next = list;
    return temp2;
}

int     vertex_repeats(s_lem_in *first)
{
    s_lem_in    *list;
    s_lem_in    *temp;

    list = first;
    while (list)
    {
        temp = list->next;
        while (temp)
        {
            if (!ft_strcmp(temp->name, list->name) || (temp->x == list->x && temp->y == list->y))
            {
                free_list(first);
                return (1);
            }
            temp = temp->next;
        }
        list = list->next;
    }
    return (0);
}

int     is_start(int i)
{
    while (i > 0)
    {
        if (!ft_strcmp("##start", file_array[i]))
            return 1;
        else if (file_array[i][0] == '#')
        {
            i--;
            continue;
        }
        else
            return (0);
    }
    return (0);
}

int     is_end(int i)
{
    while (i > 0)
    {
        if (!ft_strcmp("##end", file_array[i]))
            return 1;
        else if (file_array[i][0] == '#')
        {
            i--;
            continue;
        }
        else
            return (0);
    }
    return (0);
}

s_lem_in    *create_vertex(char *line, int id)
{
    int         i;
    s_lem_in    *list;
    int         l;

    i = 0;
    while (line[i] != ' ')
        i++;
    list = malloc(sizeof(s_lem_in));
    list->name = ft_strnew(i + 1);
    ft_strncpy(list->name, line, i);
    list->id = id;
    i++;
    l = 0;
    while (line[i + l] != ' ')
        l++;
    if (ft_strncmp(ft_itoa(ft_atoi(line + i)), line + i, l))
    {
        free(list->name);
        free(list);
        return NULL;
    }
    list->x = ft_atoi(line + i);
    while (line[i] != ' ')
        i++;
    i++;
    l = 0;
    while (line[i + l] != '\0')
        l++;
    if (ft_strncmp(ft_itoa(ft_atoi(line + i)), line + i, l))
    {
        free(list->name);
        free(list);
        return NULL;
    }
    list->y = ft_atoi(line + i);
    list->start = 0;
    list->end = 0;
    list->length;
    list->ant = 0;
    list->next = NULL;
    list->route = NULL;
    return list;
}