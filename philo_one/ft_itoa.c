/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:16:56 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/17 15:26:15 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static size_t	ft_getlength(int nbr)
{
	size_t			l;
	unsigned int	unbr;

	unbr = nbr;
	l = 0;
	if (nbr < 0)
	{
		l++;
		unbr = nbr * -1;
	}
	while (unbr != 0)
	{
		unbr /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	unbr;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_getlength(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	unbr = n;
	if (n < 0)
	{
		*str = '-';
		unbr = n * -1;
	}
	*(str + len) = '\0';
	len--;
	while (unbr != 0)
	{
		*(str + len) = unbr % 10 + '0';
		unbr /= 10;
		len--;
	}
	return (str);
}
