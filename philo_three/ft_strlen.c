#include "philo_three.h"

int32_t	ft_strlen(const char *str)
{
	int32_t		len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}
