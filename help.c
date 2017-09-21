/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:52:29 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/21 17:05:45 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_route_2(int ant, t_lem_in *temp)
{
	ft_printf("L%d-%s ", ant, temp->route->name);
	if (!temp->route->end)
	{
		temp->route->ant = ant;
		return (0);
	}
	else
		return (1);
}

int		find_route_3(int ant, t_lem_in *temp2)
{
	temp2->route->ant = ant;
	ft_printf("L%d-%s ", ant, temp2->route->name);
	return (0);
}

int		find_a_backspace(char *line, int i)
{
	while (line[i] != ' ')
		i++;
	return (i);
}

void	fill_empty_vertex(t_lem_in *list, char *line, int i)
{
	list->y = ft_atoi(line + i);
	list->start = 0;
	list->end = 0;
	list->length;
	list->ant = 0;
	list->next = NULL;
	list->route = NULL;
}

int		add_route_2(t_lem_in *first, t_lem_in *second, t_lem_in *temp)
{
	while (first->route)
	{
		if (first->route->id == second->id)
			return (1);
		first = first->route;
	}
	first->route = ft_copy(second);
	while (second->route)
		second = second->route;
	second->route = ft_copy(temp);
	return (1);
}
