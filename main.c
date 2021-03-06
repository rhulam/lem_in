/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:00:44 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/26 14:58:09 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**g_file_array;
int			g_path;
int			g_moves;

int			start_end_count_check_3(int *i)
{
	while (g_file_array[*i])
	{
		if (valid_numeric_line(g_file_array[*i]))
			break ;
		else if ((g_file_array[*i][0] == '#' && g_file_array[*i][1] != '#'))
		{
			(*i)++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}

int			*create_ants_arr(int ants)
{
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * (ants + 1));
	while (i < ants)
	{
		arr[i] = 1;
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void		validation(void)
{
	int		i;

	if (!g_file_array[0])
	{
		free_array();
		error();
	}
	if (start_end_count_check() && (i = ant_checker()))
	{
		while (g_file_array[i])
		{
			if (!line_validator(g_file_array[i]))
			{
				free_array();
				error();
			}
			i++;
		}
	}
	else
	{
		free_array();
		error();
	}
}

void		free_and_error(void)
{
	free_array();
	error();
}

int			main(void)
{
	char	*string;
	int		i;
	int		j;

	g_path = 0;
	g_moves = 0;
	i = 0;
	g_file_array = malloc(sizeof(char *) * 4096);
	g_file_array[0] = NULL;
	while ((j = get_next_line(0, &string)))
	{
		if (j < 0)
			free_and_error();
		g_file_array[i++] = ft_strdup(string);
		if (!g_file_array[i - 1] || g_file_array[i - 1][0] == '\0')
			free_and_error();
		if (!valid(g_file_array[i - 1]))
			free_and_error();
		free(string);
	}
	g_file_array[i] = NULL;
	free(string);
	validation();
	fill_adjacency_list();
	return (0);
}
