#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft.h"

typedef struct lem_in
{

}               t_lem_in;

void    error();
void    free_array(char **array);
//int     start_exists(char **file_array);
//int     end_exists(char **file_array);
int     start_end_count_check(char **file_array);
int     ant_checker(char *first_line);
int     line_validator(char *line);

#endif
