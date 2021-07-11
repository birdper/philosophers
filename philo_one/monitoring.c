#include "philo_one.h"

static int	check_how_times_eat(t_philosoph_s *phil, int times_must_eat,
							   int number_philosophers)
{
	int		i;

	i = 0;
	while (times_must_eat >= 0 && phil[i].times_eat >= times_must_eat)
	{
		if (i == number_philosophers - 1)
			return (1);
		i++;
	}
	return (0);
}

static int	check_die(t_param *param, t_philosoph_s *phil)
{
	int		current_time;
	int		i;

	i = 0;
	while (i < param->number_philosophers)
	{
		current_time = get_passedtime(param->starting_point);
		if (current_time - phil[i].time_last_meal > param->time_to_die)
		{
			param->alive = 0;
			pthread_mutex_lock(&param->print_mutex);
			print_status(" died", i + 1, get_passedtime(param->starting_point));
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *par)
{
	t_param		*param;

	param = (t_param *)par;
	while (1)
	{
		if (check_die(param, param->phil))
			return (NULL);
		if (check_how_times_eat(param->phil, param->times_must_eat,
				param->number_philosophers))
			return (NULL);
		stage(1);
	}
}
