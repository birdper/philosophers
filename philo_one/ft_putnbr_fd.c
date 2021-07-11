/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:39:41 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/17 21:11:21 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static size_t	get_length(int n)
{
	size_t			l;
	unsigned int	unbr;

	unbr = n;
	l = 0;
	if (n == 0)
		l++;
	if (n < 0)
	{
		l++;
		unbr = n * -1;
	}
	while (unbr != 0)
	{
		unbr /= 10;
		l++;
	}
	return (l);
}

static void	local_itoa(char *dst, int n, size_t len)
{
	unsigned int	unbr;
	size_t			i;

	unbr = n;
	i = len - 1;
	if (n < 0)
	{
		dst[0] = '-';
		unbr = n * -1;
		len--;
	}
	dst[i + 1] = '\0';
	while (len--)
	{
		dst[i] = unbr % 10 + '0';
		unbr /= 10;
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t		len;
	char		*str;

	len = get_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	local_itoa(str, n, len);
	write(fd, str, len * sizeof(char));
	free(str);
}
