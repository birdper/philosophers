/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:20:47 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/10 19:21:08 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lim;
	size_t	srclen;

	if (dst == NULL || src == NULL)
		return (0);
	srclen = ft_strlen((char *)src);
	lim = srclen;
	if (dstsize)
	{
		if (dstsize - 1 <= srclen)
			lim = dstsize - 1;
		i = 0;
		while (i < lim)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
