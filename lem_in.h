#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft.h"

extern int      g_path;
extern char    **file_array;

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
void        free_array();
int         start_end_count_check();
int         ant_checker();
int         line_validator(char *line);
void        fill_adjacency_list();
int         valid_numeric_line(char *line);
int         is_end(int i);
int         is_start(int i);
int         valid_route(char *line);
void        free_list(s_lem_in *list);
s_lem_in    *create_vertex(char *line, int id);
int         vertex_repeats(s_lem_in *first);
s_lem_in    *start_to_first(s_lem_in *list);
void        create_routes(s_lem_in *list, int ants);
s_lem_in    *ft_copy(s_lem_in *list);
s_lem_in    *sort_routes(s_lem_in *routes);
s_lem_in    *filter_crossing_routes(s_lem_in *routes);
void        start_ants(s_lem_in *routes, int* ants_arr, int ants);
int         find_route_2(int ant, s_lem_in *temp);
int         find_route_3(int ant, s_lem_in *temp2);

#endif
