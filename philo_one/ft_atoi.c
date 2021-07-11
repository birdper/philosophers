/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:16:00 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/12 16:37:31 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	skip_spaces(const char *str)
{
	int		i;

	i = 0;
	while ((str[i] && 9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static int	check_sign(const char *str, int i, int *sign)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			(*sign) = -1;
		i++;
	}
	return (i);
}

static int	skip_zeros(const char *str, int i)
{
	while (str[i] == '0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long		nbr;
	int			sign;
	long		long_max;
	int			d;
	int			i;

	nbr = 0;
	sign = 1;
	i = skip_spaces(str);
	i = check_sign(str, i, &sign);
	i = skip_zeros(str, i);
	long_max = (long)((unsigned long) ~ 0 >> 1);
	while (ft_isdigit(str[i]))
	{
		d = str[i] - '0';
		if (nbr > (long_max - d) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = nbr * 10 + d;
		i++;
	}
	return ((int)nbr * sign);
}
