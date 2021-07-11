#include "philo_one.h"

int	wait_monitor(t_param *param, pthread_t *monitor)
{
	int		ret;
	int		i;

	i = 0;
	pthread_join(*monitor, NULL);
	stage(param->time_to_eat + 60);
	while (i < param->number_philosophers)
	{
		ret = pthread_mutex_destroy(&(param->phil[i].fork_mutex));
		if (ret)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_destroy(&param->print_mutex))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	prepare_table(t_param *param, t_philosopher **philosophers)
{
	int		i;

	*philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			                                     * param->number_philosophers);
	if (!*philosophers)
		return (EXIT_FAILURE);
	param->phil = (t_philosoph_s *)malloc(sizeof(t_philosoph_s)
			                                     * param->number_philosophers);
	if (!param->phil)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&param->print_mutex, NULL))
		return (EXIT_FAILURE);
	i = 0;
	while (i < param->number_philosophers)
		if (pthread_mutex_init(&(param->phil[i++].fork_mutex), NULL))
			return (EXIT_FAILURE);
	i = 0;
	while (i < param->number_philosophers)
		param->phil[i++].time_last_meal = param->time_to_die;
	i = 0;
	while (i < param->number_philosophers)
		param->phil[i++].times_eat = 0;
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_philosopher	*philosophers;
	pthread_t		monitor;
	t_param			param;
	int				ret;

	ret = parse(argc, argv, &param);
	if (ret)
		return (EXIT_FAILURE);
	ret = prepare_table(&param, &philosophers);
	if (ret)
		return (EXIT_FAILURE);
	param.starting_point = get_currenttime_ms();
	ret = start_dinner(&param, philosophers, &monitor);
	if (ret)
		return (EXIT_FAILURE);
	wait_monitor(&param, &monitor);
	return (EXIT_SUCCESS);
}
