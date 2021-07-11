#include "philo_three.h"

int	is_notnumber(char *arg)
{
	char	*start;

	start = arg;
	if (*arg == '-' || *arg == '+')
		start = arg + 1;
	while (*start != '\0')
	{
		if (!ft_isdigit(*start))
			return (1);
		start++;
	}
	return (0);
}
