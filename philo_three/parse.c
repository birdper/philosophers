#include "philo_three.h"

static int	print_err(int value, int limit, char *msg)
{
	if (value < limit)
	{
		printf("Wrong input: %s %d\n", msg, value);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	validate_input(int argc, char *argv[])
{
	int		i;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	i = 1;
	while (argv[i])
	{
		if (is_notnumber(argv[i]))
		{
			printf("Wrong input: %s is not number\n", argv[i]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parse(int argc, char **argv, t_param *param)
{
	if (validate_input(argc, argv))
		return (EXIT_FAILURE);
	param->number_philosophers = ft_atoi(argv[1]);
	if (print_err(param->number_philosophers, 1, "number philosophers"))
		return (EXIT_FAILURE);
	param->time_to_die = ft_atoi(argv[2]);
	if (print_err(param->time_to_die, 0, "time to die"))
		return (EXIT_FAILURE);
	param->time_to_eat = ft_atoi(argv[3]);
	if (print_err(param->time_to_eat, 0, "time to eat"))
		return (EXIT_FAILURE);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (print_err(param->time_to_sleep, 0, "time to sleep"))
		return (EXIT_FAILURE);
	param->times_must_eat = -1;
	if (argv[5])
	{
		param->times_must_eat = ft_atoi(argv[5]);
		if (print_err(param->times_must_eat, 0, "times must eat"))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
