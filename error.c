/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:44:13 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/26 14:47:09 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(-1);
}

void	*free_vertexes(t_lem_in *first)
{
	free_list(first);
	return (NULL);
}

void	check_path(t_lem_in *routes)
{
	t_lem_in	*temp;
	t_lem_in	*temp2;
	int			i;

	if (!g_path)
		return ;
	ft_printf("##path\n");
	i = 1;
	temp = routes;
	while (temp)
	{
		temp2 = temp;
		ft_printf("#%d\n", i++);
		while (temp2)
		{
			ft_printf("%s", temp2->name);
			if (temp2->route)
				ft_printf("->");
			temp2 = temp2->route;
		}
		ft_printf("\n");
		temp = temp->next;
	}
	ft_printf("\n");
}

int		valid2(char *line, int *ants)
{
	if (find_ants(line) == 2)
		*ants = 1;
	else if (find_ants(line) == 1)
		return (1);
	else
		return (0);
	return (1);
}

int		valid3(int *start, int *end)
{
	if (*start || *end == 1)
		return (0);
	*start = 1;
	return (1);
}
