/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:25:19 by rhulam            #+#    #+#             */
/*   Updated: 2017/09/26 15:25:39 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid4(int *start, int *end)
{
	if (*end || *start == 1)
		return (0);
	*end = 1;
	return (1);
}

int		valid5(int *link, int *start, int *end)
{
	*link = 1;
	if (!(*start) || !(*end))
		return (0);
	return (1);
}
