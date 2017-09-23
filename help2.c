/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:06:27 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/21 17:11:41 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem_in		*fill_vertex_list_2(t_lem_in *list, int i, int id)
{
	list->next = create_vertex(g_file_array[i], id);
	return (list->next);
}

void			sort_routes_2(t_lem_in **temp3, t_lem_in **temp2,
							t_lem_in **temp, t_lem_in **previous2)
{
	*temp3 = (*temp2)->next;
	if (!the_same(*temp2, (*temp)->next))
		(*temp2)->next = (*temp)->next;
	else
		(*temp2)->next = *temp;
	(*previous2)->next = *temp;
	(*temp)->next = *temp3;
	*temp3 = *temp2;
	*temp2 = *temp;
	*temp = *temp3;
}

int				add_new_route_2(t_lem_in **temp, t_lem_in **temp2)
{
	int			i;

	i = 1;
	while (*temp)
	{
		(*temp2)->route = ft_copy(*temp);
		*temp2 = (*temp2)->route;
		(*temp2)->next = NULL;
		*temp = (*temp)->next;
		i++;
	}
	return (i);
}

int				find_end(t_lem_in *list)
{
	t_lem_in	*temp;

	temp = list;
	while (!temp->end)
		temp = temp->next;
	return (temp->id);
}

int				start_end_count_check_2(int *i, int *start_count)
{
	if (!ft_strcmp(g_file_array[*i], "##start") && g_file_array[*i + 1])
	{
		(*i)++;
		while (g_file_array[*i])
		{
			if (valid_numeric_line(g_file_array[*i]))
				break ;
			else if ((g_file_array[*i][0] == '#' &&
				g_file_array[*i][1] != '#'))
			{
				(*i)++;
				continue;
			}
			else
				return (0);
		}
		if (g_file_array[*i])
			(*start_count)++;
	}
	return (1);
}
