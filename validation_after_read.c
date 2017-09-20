/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_after_read.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:44:15 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/20 17:51:37 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**g_file_array;

int			valid_route(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '#' || line[i] == 'L' || line[i] == ' ' ||
			line[i] == '\t' || line[i] == '\r')
		return (0);
	while (line[i] != '-' && line[i] != '\0' && line[i] != ' ' &&
			line[i] != '\t' && line[i] != '\r')
		i++;
	if (line[i] != '-')
		return (0);
	i++;
	if (line[i] == '#' || line[i] == 'L' || line[i] == ' ' ||
			line[i] == '\t' || line[i] == '\r')
		return (0);
	while (line[i] != '-' && line[i] != '\0' && line[i] != ' ' &&
			line[i] != '\t' && line[i] != '\r')
		i++;
	if (line[i] != '\0')
		return (0);
	return (1);
}

int			valid_numeric_line(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '#' || line[i] == 'L' || line[i] == ' ' ||
			line[i] == '\t' || line[i] == '\r')
		return (0);
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	i++;
	while (isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		return (0);
	i++;
	while (isdigit(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	return (1);
}

int			start_end_count_check(void)
{
	int		i;
	int		start_count;
	int		end_count;

	i = -1;
	start_count = 0;
	end_count = 0;
	while (g_file_array[++i])
	{
		if (!start_end_count_check_2(&i, &start_count))
			return (0);
		else if (!ft_strcmp(g_file_array[i], "##end") && g_file_array[i + 1])
		{
			i++;
			if (!start_end_count_check_3(&i))
				return (0);
			if (g_file_array[i])
				end_count++;
		}
	}
	if (start_count == 1 && end_count == 1)
		return (1);
	return (0);
}

int			ant_checker(void)
{
	int		i;
	char	*first_line;

	i = 0;
	first_line = g_file_array[0];
	while (isdigit(first_line[i]))
		i++;
	if (first_line[i] == '\0' && !ft_strcmp(ft_itoa(ft_atoi(first_line)),
					first_line) && ft_atoi(first_line) > 0)
		return (1);
	return (0);
}

int			line_validator(char *line)
{
	if (line[0] == '#')
		return (1);
	else
	{
		if (!valid_numeric_line(line) && !valid_route(line))
			return (0);
	}
	return (1);
}
