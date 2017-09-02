#include "lem_in.h"
void    free_array(char **array)
{
    int     i;

    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}

void    free_list(s_lem_in *list)
{
    s_lem_in    *tmp;

    tmp = list;
    while (tmp)
    {
        if (tmp->name)
            free(tmp->name);
        list = list->next;
        free(tmp);
        tmp = list;
    }
}

void    free_int_array(int **array)
{
    int     i;

    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}