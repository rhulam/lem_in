/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:02:21 by rhulam            #+#    #+#             */
/*   Updated: 2016/11/21 15:42:33 by rhulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	if (n)
	{
		while (n)
		{
			*str++ = '\0';
			n--;
		}
	}
}
