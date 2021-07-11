#include "philo_two.h"

static void	take_fork(int number, t_param *param)
{
	sem_wait(param->forks_sem);
	print_with_lock(" has taken a fork", number, param);
	sem_wait(param->forks_sem);
	print_with_lock(" has taken a fork", number, param);
}

static void	drop_fork(const t_param *param)
{
	sem_post(param->forks_sem);
	sem_post(param->forks_sem);
}

static void	*start_lyfecycle(void *par)
{
	t_param		*param;
	int			number;

	param = (t_param *)par;
	number = param->starting_number++;
	if (param->times_must_eat == 0)
		return (0);
	while (param->alive)
	{
		take_fork(number, param);
		param->phil[number - 1].time_last_meal = get_passedtime(
				param->starting_point);
		print_with_lock(" is eating", number, param);
		param->phil[number - 1].times_eat++;
		stage(param->time_to_eat);
		drop_fork(param);
		print_with_lock(" is sleeping", number, param);
		stage(param->time_to_sleep);
		print_with_lock(" is thinking", number, param);
	}
	return (NULL);
}

int	start_dinner(t_param *param, t_philosopher *philosophers,
				pthread_t *monitor)
{
	int		ret;
	int		i;

	i = 0;
	while (i < param->number_philosophers)
	{
		ret = pthread_create(&(philosophers[i].pthread), NULL,
				 start_lyfecycle, param);
		if (ret)
			return (EXIT_FAILURE);
		pthread_detach(philosophers[i].pthread);
		i++;
	}
	ret = pthread_create(monitor, NULL, monitoring, param);
	if (ret)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
