/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:28:56 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/19 22:30:35 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	emptysize;

	if ((dst || src) == 0)
		return (0);
	srclen = ft_strlen((char *)src);
	dstlen = ft_strlen(dst);
	emptysize = dstsize - dstlen;
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	return (ft_strlcpy(&dst[dstlen], src, emptysize) + dstlen);
}
