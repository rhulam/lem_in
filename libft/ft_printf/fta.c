/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 16:27:45 by rhulam            #+#    #+#             */
/*   Updated: 2017/04/30 16:28:51 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fta(char *s, int n)
{
	free(s);
	return (ft_alloc(n));
}
