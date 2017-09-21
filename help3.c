/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:39:09 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/21 17:39:22 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ints(char *line, int i, int l)
{
	char	*temp;

	temp = ft_itoa(ft_atoi(line + i));
	if (ft_strncmp(temp, line + i, l))
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}
