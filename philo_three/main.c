#include "philo_three.h"

int	wait_monitor(t_param *param)
{
	stage(param->time_to_eat + param->time_to_eat);
	unlink_semaphors();
	return (EXIT_SUCCESS);
}

int	prepare_table(t_param *param)
{
	unlink_semaphors();
	param->forks_sem = sem_open("/forks_sem", O_CREAT, 0666,
			param->number_philosophers);
	if (param->forks_sem == SEM_FAILED)
		return (EXIT_FAILURE);
	param->print_sem = sem_open("/print_sem", O_CREAT, 0666, 1);
	if (param->print_sem == SEM_FAILED)
		return (EXIT_FAILURE);
	param->phil.time_last_meal = param->time_to_die;
	param->phil.times_eat = 0;
	param->starting_number = 1;
	param->alive = 1;
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_param			param;

	if (parse(argc, argv, &param))
		return (EXIT_FAILURE);
	if (prepare_table(&param))
		return (EXIT_FAILURE);
	param.starting_point = get_currenttime_ms();
	if (start_dinner(&param))
		return (EXIT_FAILURE);
	wait_monitor(&param);
	return (EXIT_SUCCESS);
}
