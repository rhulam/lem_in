#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft.h"

typedef struct lem_in
{
    int             id;
    char            *name;
    int             x;
    int             y;
    int             start;
    int             end;
    struct lem_in   *next;

}               s_lem_in;

void    error();
void    free_array(char **array);
int     start_end_count_check(char **file_array);
int     ant_checker(char *first_line);
int     line_validator(char *line);
void    fill_adjacency_list(char **file_array);
int     valid_numeric_line(char *line);
void    create_new_vertex(s_lem_in *list, char *line);
int     is_end(char *line);
int     is_start(char *line);
int     valid_route(char *line);
void    free_list(s_lem_in *list);
void    free_int_array(int **array);
int     double_vertexes(s_lem_in *first_list);
int     create_routes(s_lem_in *first_list, char **routes_matrix);

#endif
