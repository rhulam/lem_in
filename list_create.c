/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:22:47 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/21 17:32:31 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem_in		*ft_copy(t_lem_in *list)
{
	t_lem_in	*copy;

	copy = malloc(sizeof(t_lem_in));
	copy->name = ft_strdup(list->name);
	copy->id = list->id;
	copy->x = list->x;
	copy->y = list->y;
	copy->start = list->start;
	copy->end = list->end;
	copy->length = list->length;
	copy->ant = 0;
	copy->next = list;
	copy->route = NULL;
	return (copy);
}

int				add_route(t_lem_in *list, char *s1, char *s2)
{
	t_lem_in	*temp;
	t_lem_in	*first;
	t_lem_in	*second;

	temp = list;
	first = NULL;
	second = NULL;
	while (temp)
	{
		if (!ft_strcmp(temp->name, s1))
			first = temp;
		if (!ft_strcmp(temp->name, s2))
			second = temp;
		temp = temp->next;
	}
	free(s1);
	free(s2);
	if (!first || !second)
		return (0);
	temp = first;
	return (add_route_2(first, second, temp));
}

int				fill_routes(t_lem_in *first)
{
	int			i;
	int			j;
	int			k;
	char		*temp1;
	char		*temp2;

	i = -1;
	while (g_file_array[++i])
	{
		if (!valid_route(g_file_array[i]))
			continue;
		j = 0;
		k = 0;
		while (g_file_array[i][j] != '-')
			j++;
		temp1 = ft_strnew(j + 1);
		ft_strncpy(temp1, g_file_array[i], j++);
		while (g_file_array[i][j + k] != '\0')
			k++;
		temp2 = ft_strnew(k + 1);
		ft_strncpy(temp2, g_file_array[i] + j, k);
		if (!add_route(first, temp1, temp2))
			return (0);
	}
	return (1);
}

t_lem_in		*fill_vertex_list(int i)
{
	t_lem_in	*list;
	t_lem_in	*first;
	int			id;

	first = NULL;
	list = NULL;
	id = 1;
	while (g_file_array[++i])
	{
		if (!valid_numeric_line(g_file_array[i]))
			continue;
		if (!first)
		{
			first = create_vertex(g_file_array[i], id);
			list = first;
		}
		else
			list = fill_vertex_list_2(list, i, id);
		if (!list)
			return (free_vertexes(first));
		id++;
		list->start = is_start(i - 1) ? 1 : 0;
		list->end = is_end(i - 1) ? 1 : 0;
	}
	return (first);
}

void			fill_adjacency_list(void)
{
	t_lem_in	*list;
	int			i;

	i = -1;
	list = fill_vertex_list(i);
	if (!list)
		error();
	if (vertex_repeats(list))
		error();
	if (!fill_routes(list))
		error();
	list = start_to_first(list);
	create_routes(list, ft_atoi(g_file_array[0]));
}
