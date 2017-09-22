/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:12:02 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/21 17:31:42 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include "libft/libft.h"

extern int			g_path;
extern int			g_moves;
extern char			**g_file_array;

typedef struct		s_lem_in
{
	int				id;
	char			*name;
	int				x;
	int				y;
	int				start;
	int				end;
	int				ant;
	int				length;
	struct s_lem_in	*next;
	struct s_lem_in	*route;

}					t_lem_in;

void				error(void);
void				free_array(void);
int					start_end_count_check(void);
int					ant_checker(void);
int					line_validator(char *line);
void				fill_adjacency_list(void);
int					valid_numeric_line(char *line);
int					is_end(int i);
int					is_start(int i);
int					valid_route(char *line);
void				free_list(t_lem_in *list);
t_lem_in			*create_vertex(char *line, int id);
int					vertex_repeats(t_lem_in *first);
t_lem_in			*start_to_first(t_lem_in *list);
void				create_routes(t_lem_in *list, int ants);
t_lem_in			*ft_copy(t_lem_in *list);
t_lem_in			*sort_routes(t_lem_in *routes, t_lem_in *temp,
					t_lem_in *route);
t_lem_in			*filter_crossing_routes(t_lem_in *routes);
void				start_ants(t_lem_in *routes, int *ants_arr, int ants);
int					find_route_2(int ant, t_lem_in *temp);
int					find_route_3(int ant, t_lem_in *temp2);
void				*free_a_vertex(t_lem_in *list);
int					find_a_backspace(char *line, int i);
void				fill_empty_vertex(t_lem_in *list, char	*line, int i);
int					add_route_2(t_lem_in *first, t_lem_in *second,
					t_lem_in *temp);
void				*free_vertexes(t_lem_in *first);
t_lem_in			*fill_vertex_list_2(t_lem_in *list, int i, int id);
int					the_same(t_lem_in *a, t_lem_in *b);
void				sort_routes_2(t_lem_in **temp3, t_lem_in **temp2,
					t_lem_in **temp, t_lem_in **previous2);
int					add_new_route_2(t_lem_in **temp, t_lem_in **temp2);
int					*create_ants_arr(int ants);
void				free_last_list(t_lem_in *list);
int					find_end(t_lem_in *list);
int					start_end_count_check_2(int *i, int *start_count);
int					start_end_count_check_3(int *i);
void				check_path(t_lem_in *routes);
void				free_full_list(t_lem_in *list);
int					check_ints(char *line, int i, int l);

#endif
