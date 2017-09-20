/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:28:33 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/20 17:33:59 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			**g_file_array;

int				passed_vertex(t_lem_in *route, t_lem_in *list)
{
	t_lem_in	*temp;

	temp = route;
	while (temp)
	{
		if (temp->id == list->id)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_lem_in		*push_to_last(t_lem_in *route, t_lem_in *copy)
{
	t_lem_in	*temp;

	if (!route)
	{
		route = copy;
		route->next = NULL;
		return (route);
	}
	temp = route;
	while (temp->next)
		temp = temp->next;
	temp->next = copy;
	temp->next->next = NULL;
	return (route);
}

t_lem_in		*add_new_route(t_lem_in *routes, t_lem_in *route)
{
	t_lem_in	*temp;
	t_lem_in	*temp2;
	t_lem_in	*current;
	int			i;

	temp = route;
	temp2 = routes;
	if (temp2)
	{
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = ft_copy(temp);
		temp2 = temp2->next;
	}
	else
	{
		temp2 = ft_copy(temp);
		routes = temp2;
	}
	temp2->next = NULL;
	current = temp2;
	temp = temp->next;
	i = add_new_route_2(&temp, &temp2);
	current->length = i;
	return (routes);
}

void			routes_exists(t_lem_in *list, t_lem_in **routes, int end,
							t_lem_in *route)
{
	route = push_to_last(route, ft_copy(list));
	if (list->id == end)
	{
		*routes = add_new_route(*routes, route);
		return ;
	}
	while (list)
	{
		if (!passed_vertex(route, list))
		{
			routes_exists(list->next, routes, end, route);
			free_last_list(route);
		}
		list = list->route;
		if (!list)
			continue;
	}
}

void			create_routes(t_lem_in *list, int ants)
{
	t_lem_in	*routes;
	t_lem_in	*route;
	t_lem_in	*temp;
	int			*ants_arr;
	int			i;

	routes = NULL;
	route = NULL;
	i = 0;
	routes_exists(list, &routes, find_end(list), route);
	if (!routes)
		error();
	temp = routes;
	route = NULL;
	routes = sort_routes(routes, temp, route);
	routes = filter_crossing_routes(routes);
	while (g_file_array[i])
	{
		ft_printf("%s\n", g_file_array[i]);
		i++;
	}
	ft_printf("\n");
	ants_arr = create_ants_arr(routes, ants);
	start_ants(routes, ants_arr, ants);
}
