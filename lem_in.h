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
    int             ant;
    int             length;
    struct lem_in   *next;
    struct lem_in   *route;

}               s_lem_in;

void        error();
void        free_array(char **array);
int         start_end_count_check(char **file_array);
int         ant_checker(char *first_line);
int         line_validator(char *line);
void        fill_adjacency_list(char **file_array);
int         valid_numeric_line(char *line);
int         is_end(char *line);
int         is_start(char *line);
int         valid_route(char *line);
void        free_list(s_lem_in *list);
s_lem_in    *create_vertex(char *line, int id);
int         vertex_repeats(s_lem_in *first);
s_lem_in    *start_to_first(s_lem_in *list);
void        create_routes(s_lem_in *list, int ants);
s_lem_in    *ft_copy(s_lem_in *list);

#endif
