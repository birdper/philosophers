#include "philo_three.h"

static int	check_how_times_eat(t_philosopher *phil, int times_must_eat,
								  t_param *param)
{
	if (times_must_eat >= 0 && phil->times_eat >= times_must_eat)
	{
		drop_fork(param);
		return (1);
	}
	return (0);
}

static int	check_last_meal(t_param *param, t_philosopher *phil)
{
	int		current_time;

	current_time = get_passedtime(param->starting_point);
	if (current_time - phil->time_last_meal > param->time_to_die)
	{
		param->alive = 0;
		sem_wait(param->print_sem);
		print_status(" died", param->starting_number,
			get_passedtime(param->starting_point));
		return (1);
	}
	return (0);
}

void	*monitoring(void *par)
{
	t_param		*param;

	param = (t_param *)par;
	while (1)
	{
		if (check_last_meal(param, &param->phil))
			exit(EXIT_FAILURE);
		if (check_how_times_eat(&param->phil, param->times_must_eat, param))
			exit(EXIT_SUCCESS);
		stage(1);
	}
}
