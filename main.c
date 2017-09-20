#include "lem_in.h"

char    **file_array;

void    validation()
{
    int     i;

    i = 1;
    if (!file_array[0])
    {
        free_array();
        error();
    }
    if (start_end_count_check() && ant_checker())
    {
        while (file_array[i])
        {
            if (!line_validator(file_array[i]))
            {
                free_array();
                error();
            }
            i++;
        }
    }
    else
    {
        free_array();
        error();
    }
}

int     main(void)
{
    char    *string;
    int     i;
    i = 0;
    file_array = malloc(sizeof(char *) * 4096);
    file_array[0] = NULL;
    while (get_next_line(0, &string))
    {
        file_array[i++] = ft_strdup(string);
        free(string);
    }
    file_array[i] = NULL;
    free(string);
    validation();
    fill_adjacency_list();
    return 0;
}