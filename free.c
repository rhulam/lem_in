#include "lem_in.h"

char    **file_array;

void    free_array()
{
    int     i;

    i = 0;
    while (file_array[i])
        free(file_array[i++]);
    free(file_array);
}

void    free_list(s_lem_in *list)
{
    s_lem_in    *tmp;
    s_lem_in    *tmp2;
    s_lem_in    *tmp3;

    tmp = list;
    while (tmp)
    {
        if (tmp->name)
            free(tmp->name);
        tmp2 = tmp->route;
        while (tmp2)
        {
            if (tmp2->name)
                free(tmp2->name);
            tmp3 = tmp2->next;
            free(tmp2);
            tmp2 = tmp3;
        }
        list = list->next;
        free(tmp);
        tmp = list;
    }
}