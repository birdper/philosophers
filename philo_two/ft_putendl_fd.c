/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:17:43 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/17 21:14:24 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_putendl_fd(const char *str, int fd)
{
	if (str == NULL)
		return ;
	write(fd, str, ft_strlen(str) * sizeof(char));
	write(fd, "\n", sizeof(char));
}
