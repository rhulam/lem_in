#include "lem_in.h"

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

int     is_start(char *line)
{
    if (!ft_strcmp("##start", line))
        return 1;
    return (0);
}

int     is_end(char *line)
{
    if (!ft_strcmp("##end", line))
        return 1;
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
    list->next = NULL;
    list->route = NULL;
    return list;
}