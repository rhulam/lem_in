/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:06:21 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/20 17:07:18 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				crossing(t_lem_in *l1, t_lem_in *l2)
{
	t_lem_in	*temp1;
	t_lem_in	*temp2;

	if (!l1 || !l2)
		return (0);
	temp1 = l1->route;
	while (temp1)
	{
		temp2 = l2->route;
		while (temp2)
		{
			if (temp2->id == temp1->id && temp2->route)
				return (1);
			temp2 = temp2->route;
		}
		temp1 = temp1->route;
	}
	return (0);
}

t_lem_in		*filter_crossing_routes(t_lem_in *routes)
{
	t_lem_in	*temp;
	t_lem_in	*temp2;
	t_lem_in	*previous;

	temp = routes;
	while (temp)
	{
		temp2 = temp->next;
		previous = temp;
		while (temp2)
		{
			if (crossing(temp, temp2))
			{
				previous->next = temp2->next;
				temp2->next = NULL;
				free_full_list(temp2);
				temp2 = previous;
			}
			previous = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (routes);
}

int				the_same(t_lem_in *a, t_lem_in *b)
{
	t_lem_in	*temp;
	t_lem_in	*temp2;

	temp = a;
	temp2 = b;
	while (temp)
	{
		if (temp->id != temp2->id)
			return (0);
		temp = temp->route;
		temp2 = temp2->route;
	}
	return (1);
}

t_lem_in		*sort_routes(t_lem_in *routes, t_lem_in *temp, t_lem_in *prev)
{
	t_lem_in	*temp2;
	t_lem_in	*temp3;
	t_lem_in	*previous2;

	while (temp)
	{
		temp2 = temp->next;
		previous2 = temp;
		while (temp2)
		{
			if (temp->length > temp2->length)
			{
				if (prev)
					prev->next = temp2;
				else
					routes = temp2;
				sort_routes_2(&temp3, &temp2, &temp, &previous2);
			}
			previous2 = temp2;
			temp2 = temp2->next;
		}
		prev = temp;
		temp = temp->next;
	}
	return (routes);
}
