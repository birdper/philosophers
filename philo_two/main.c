#include "philo_two.h"

static void	unlink_sem(void)
{
	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
}

static int	wait_monitor(t_param *param, pthread_t *monitor)
{
	pthread_join(*monitor, NULL);
	stage(param->time_to_eat * 2);
	unlink_sem();
	return (EXIT_SUCCESS);
}

static int	serve_table(t_param *param)
{
	unlink_sem();
	param->forks_sem = sem_open("/forks_sem", O_CREAT, 0666,
			param->number_philosophers);
	if (param->forks_sem == SEM_FAILED)
		return (EXIT_FAILURE);
	param->print_sem = sem_open("/print_sem", O_CREAT, 0666, 1);
	if (param->print_sem == SEM_FAILED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	prepare_table(t_param *param)
{
	int		i;

	param->phil = (t_philosopher *)malloc(sizeof(t_philosopher)
			                                     * param->number_philosophers);
	if (!param->phil)
		return (EXIT_FAILURE);
	if (serve_table(param))
		return (EXIT_FAILURE);
	i = 0;
	while (i < param->number_philosophers)
	{
		param->phil[i].time_last_meal = param->time_to_die;
		param->phil[i].times_eat = 0;
		i++;
	}
	param->alive = 1;
	param->starting_number = 1;
	param->starting_point = get_currenttime_ms();
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_param			param;
	pthread_t		monitor;

	if (parse(argc, argv, &param))
		return (EXIT_FAILURE);
	if (prepare_table(&param))
		return (EXIT_FAILURE);
	if (start_dinner(&param, param.phil, &monitor))
		return (EXIT_FAILURE);
	wait_monitor(&param, &monitor);
	return (EXIT_SUCCESS);
}
