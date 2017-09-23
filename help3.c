/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:39:09 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/23 12:54:01 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ints(char *line, int i, int l)
{
	char		*temp;

	temp = ft_itoa(ft_atoi(line + i));
	if (ft_strncmp(temp, line + i, l))
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int		get_ants(void)
{
	int			i;

	i = 0;
	while (g_file_array[i][0] == '#')
		i++;
	return (ft_atoi(g_file_array[i]));
}

int     find_ants(char *line)
{
    int     i;
    char    *temp;

    i = 0;
    if (line[0] == '#' && line[1] != '#')
        return (1);
    else
    {
        while (isdigit(line[i]))
            i++;
        temp = ft_itoa(ft_atoi(line));
        if (line[i] == '\0' && !ft_strcmp(temp, line) && ft_atoi(line) > 0)
            return (2);
    }
    return (0);
}

int     check_s_e(int *start, int *end, char *line)
{
    if (line[0] == '#' && line[1] != '#')
        return (1);
    else
    {
        if (valid_numeric_line(line))
        {
            if (*start == 1)
                (*start)++;
            else if (*end == 1)
                (*end)++;
            return (1);
        }
    }
    return (0);
}

int		valid(char *line)
{
	static int	ants = 0;
    static int  start = 0;
    static int  end = 0;

    if (!line || line[0] == '\0')
        return (0);
    if (!ants)
    {
        if (find_ants(line) == 2)
            ants = 1;
        else if (find_ants(line) == 1)
            return (1);
        else
            return (0);
    }
    else if (!ft_strcmp("##start", line))
    {
        if (start || end == 1)
            return (0);
        start = 1;
    }
    else if (!ft_strcmp("##end", line))
    {
        if (end || start == 1)
            return (0);
        end = 1;
    }
    else if (start == 1 || end == 1)
    {
        if (!check_s_e(&start, &end, line))
            return (0);
    }
    else if (line[0] == '#')
        return (1);
    else if (!valid_numeric_line(line) && !valid_route(line))
        return (0);
	return (1);
}
