/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:10:36 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/20 15:22:27 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				empty(int *arr, int ants)
{
	int			i;

	i = 0;
	while (i < ants)
	{
		if (arr[i])
			return (0);
		i++;
	}
	return (1);
}

t_lem_in		*find_empty(t_lem_in *list)
{
	t_lem_in	*temp;

	temp = list;
	while (temp)
	{
		if (!temp->route->ant)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int				find_route(t_lem_in *routes, int ant, int ants)
{
	t_lem_in	*temp;
	t_lem_in	*temp2;

	temp = routes;
	while (temp)
	{
		if (!temp->route->ant)
			return (find_route_2(ant, temp));
		else
		{
			temp2 = find_empty(temp);
			if (temp2)
			{
				if (temp2->length - temp->length < ants)
					return (find_route_3(ant, temp2));
			}
			else
				return (0);
		}
		temp = temp->next;
	}
	return (0);
}

int				move_it(t_lem_in *routes, int ant, int ants, int j)
{
	t_lem_in	*temp;
	t_lem_in	*temp2;

	temp = routes;
	while (temp)
	{
		temp2 = temp->route;
		while (temp2)
		{
			if (temp2->ant == ant)
				if (!temp2->route->ant)
				{
					temp2->ant = 0;
					ft_printf("L%d-%s ", ant, temp2->route->name);
					if (!temp2->route->end)
						temp2->route->ant = ant;
					else
						j = 1;
					return (j);
				}
			temp2 = temp2->route;
		}
		temp = temp->next;
	}
	return (find_route(routes, ant, ants));
}

void			start_ants(t_lem_in *routes, int *ants_arr, int ants)
{
	int			i;
	int			j;

	j = 0;
	while (!empty(ants_arr, ants))
	{
		i = 0;
		while (i < ants)
		{
			if (ants_arr[i])
				if (move_it(routes, i + 1, ants, j))
					ants_arr[i] = 0;
			i++;
		}
		ft_printf("\n");
	}
}
