/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:46:36 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/21 17:04:00 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_array(void)
{
	int			i;

	i = 0;
	while (g_file_array[i])
		free(g_file_array[i++]);
	free(g_file_array);
}

void			free_list(t_lem_in *list)
{
	t_lem_in	*tmp;
	t_lem_in	*tmp2;
	t_lem_in	*tmp3;

	tmp = list;
	while (tmp)
	{
		if (tmp->name)
			free(tmp->name);
		tmp2 = tmp->route;
		while (tmp2)
		{
			if (tmp2->name)
				free(tmp2->name);
			tmp3 = tmp2->next;
			free(tmp2);
			tmp2 = tmp3;
		}
		list = list->next;
		free(tmp);
		tmp = list;
	}
}

void			free_full_list(t_lem_in *list)
{
	t_lem_in	*temp;
	t_lem_in	*temp2;
	t_lem_in	*temp3;

	temp = list;
	while (temp)
	{
		temp2 = temp->route;
		free(temp->name);
		while (temp2)
		{
			if (temp2->name)
				free(temp2->name);
			temp3 = temp2->route;
			free(temp2);
			temp2 = temp3;
		}
		temp3 = temp->next;
		free(temp);
		temp = temp3;
	}
}

void			*free_a_vertex(t_lem_in *list)
{
	free(list->name);
	free(list);
	return (NULL);
}

void			free_last_list(t_lem_in *list)
{
	t_lem_in	*temp;

	temp = list;
	if (!temp->next)
	{
		free(temp->name);
		free(temp);
		return ;
	}
	while (temp->next->next)
		temp = temp->next;
	free(temp->next->name);
	free(temp->next);
	temp->next = NULL;
}
