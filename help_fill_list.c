/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fill_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:53:24 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/20 15:54:31 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			**g_file_array;

t_lem_in		*start_to_first(t_lem_in *list)
{
	t_lem_in	*temp1;
	t_lem_in	*temp2;

	if (list->start)
		return (list);
	temp1 = list;
	while (!temp1->next->start)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = temp1->next->next;
	temp2->next = list;
	return (temp2);
}

int				vertex_repeats(t_lem_in *first)
{
	t_lem_in	*list;
	t_lem_in	*temp;

	list = first;
	while (list)
	{
		temp = list->next;
		while (temp)
		{
			if (!ft_strcmp(temp->name, list->name) ||
				(temp->x == list->x && temp->y == list->y))
			{
				free_list(first);
				return (1);
			}
			temp = temp->next;
		}
		list = list->next;
	}
	return (0);
}

int				is_start(int i)
{
	while (i > 0)
	{
		if (!ft_strcmp("##start", g_file_array[i]))
			return (1);
		else if (g_file_array[i][0] == '#')
		{
			i--;
			continue;
		}
		else
			return (0);
	}
	return (0);
}

int				is_end(int i)
{
	while (i > 0)
	{
		if (!ft_strcmp("##end", g_file_array[i]))
			return (1);
		else if (g_file_array[i][0] == '#')
		{
			i--;
			continue;
		}
		else
			return (0);
	}
	return (0);
}

t_lem_in		*create_vertex(char *line, int id)
{
	int			i;
	t_lem_in	*list;
	int			l;

	i = 0;
	i = find_a_backspace(line, i);
	list = malloc(sizeof(t_lem_in));
	list->name = ft_strnew(i + 1);
	ft_strncpy(list->name, line, i++);
	list->id = id;
	l = 0;
	l = find_a_backspace(line + i, l);
	if (ft_strncmp(ft_itoa(ft_atoi(line + i)), line + i, l))
		return (free_a_vertex(list));
	list->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	i++;
	l = 0;
	l = find_a_backspace(line + i, l);
	if (ft_strncmp(ft_itoa(ft_atoi(line + i)), line + i, l))
		return (free_a_vertex(list));
	fill_empty_vertex(list, line, i);
	return (list);
}
