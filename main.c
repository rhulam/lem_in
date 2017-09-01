#include "lem_in.h"

void    validation(char **file_array)
{
    int     i;

    i = 1;
    if (!file_array[0])
    {
        free_array(file_array);
        error();
    }
    if (start_end_count_check(file_array) && ant_checker(file_array[0]))
    {
        while (file_array[i])
        {
            if (!line_validator(file_array[i]))
            {
                free_array(file_array);
                error();
            }
            i++;
        }
    }
    else
    {
        free_array(file_array);
        error();
    }
}

int     main()
{
    char    **file_array;
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
    validation(file_array);
    i = 0;
    while (file_array[i])
    {
        ft_printf("%s\n", file_array[i]);
        i++;
    }
    return 0;
}