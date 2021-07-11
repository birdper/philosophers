#include "philo_one.h"

static void	take_fork(int number, t_param *param)
{
	if (number % 2 == 0)
	{
		pthread_mutex_lock(&param->phil[number - 1].fork_mutex);
		print_w_lock(" has taken a fork", number, param);
		if (number == param->number_philosophers)
			pthread_mutex_lock(&(param->phil[0].fork_mutex));
		else
			pthread_mutex_lock(&(param->phil[number].fork_mutex));
		print_w_lock(" has taken a fork", number, param);
	}
	else
	{
		if (number == param->number_philosophers)
			pthread_mutex_lock(&(param->phil[0].fork_mutex));
		else
			pthread_mutex_lock(&(param->phil[number].fork_mutex));
		print_w_lock(" has taken a fork", number, param);
		pthread_mutex_lock(&(param->phil[number - 1].fork_mutex));
		print_w_lock(" has taken a fork", number, param);
	}
}

static void	drop_fork(int number, const t_param *param)
{
	if (number % 2 != 0)
	{
		pthread_mutex_unlock(&(param->phil[number - 1].fork_mutex));
		if (number == param->number_philosophers)
			pthread_mutex_unlock(&(param->phil[0].fork_mutex));
		else
			pthread_mutex_unlock(&(param->phil[number].fork_mutex));
	}
	else
	{
		if (number == param->number_philosophers)
			pthread_mutex_unlock(&(param->phil[0].fork_mutex));
		else
			pthread_mutex_unlock(&(param->phil[number].fork_mutex));
		pthread_mutex_unlock(&(param->phil[number - 1].fork_mutex));
	}
}

static void	*start_lyfecycle(void *par)
{
	t_param		*param;
	int			number;
	int			time_ms;

	param = (t_param *)par;
	number = param->starting_number++;
	if (param->times_must_eat == 0)
		return (0);
	while (param->alive)
	{
		take_fork(number, param);
		time_ms = get_passedtime(param->starting_point);
		param->phil[number - 1].time_last_meal = time_ms;
		if (!param->alive)
			return (0);
		print_w_lock(" is eating", number, param);
		param->phil[number - 1].times_eat++;
		stage(param->time_to_eat);
		drop_fork(number, param);
		print_w_lock(" is sleeping", number, param);
		stage(param->time_to_sleep);
		print_w_lock(" is thinking", number, param);
	}
	return (NULL);
}

int	start_dinner(t_param *param, t_philosopher *philosophers,
				pthread_t *monitor)
{
	int		ret;
	int		i;

	i = 0;
	param->starting_number = 1;
	param->alive = 1;
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
