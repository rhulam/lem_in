#include "lem_in.h"
void    free_array(char **array)
{
    int     i;

    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}