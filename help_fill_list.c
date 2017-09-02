#include "lem_in.h"

void    create_new_vertex(s_lem_in *list, char *line)
{
    int         i;
    s_lem_in    *next;

    i = 0;
    while (line[i] != ' ')
        i++;
    ft_strncpy(list->name = ft_strnew(i), line, i);
    list->x = ft_atoi(line + ++i);
    while (line[i] != ' ')
        i++;
    list->y = ft_atoi(line + ++i);
    next = malloc(sizeof(s_lem_in));
    next->next = NULL;
    next->id = list->id + 1;
    next->name = NULL;
    list->next = next;
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