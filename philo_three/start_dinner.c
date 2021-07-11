#include "philo_three.h"
#define CHILD 0

static void	take_fork(int number, t_param *param)
{
	sem_wait(param->forks_sem);
	print_w_lock(" has taken a fork", number, param);
	sem_wait(param->forks_sem);
	print_w_lock(" has taken a fork", number, param);
}

void	drop_fork(const t_param *param)
{
	sem_post(param->forks_sem);
	sem_post(param->forks_sem);
}

static void	*start_lyfecycle(t_param *param)
{
	int			number;

	number = param->starting_number;
	if (param->times_must_eat == 0)
		exit(0);
	while (param->alive)
	{
		take_fork(number, param);
		param->phil.time_last_meal = get_passedtime(param->starting_point);
		print_w_lock(" is eating", number, param);
		param->phil.times_eat++;
		stage(param->time_to_eat);
		drop_fork(param);
		print_w_lock(" is sleeping", number, param);
		stage(param->time_to_sleep);
		print_w_lock(" is thinking", number, param);
	}
	exit(0);
}

void	waits(t_param *param, pid_t pids[])
{
	int		i;
	int		status;
	int		pid;

	i = 0;
	while (i < param->number_philosophers)
	{
		pid = waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) > 0)
			{
				i = 0;
				while (i < param->number_philosophers)
				{
					if (pid != pids[i])
						kill(pids[i], SIGTERM);
					i++;
				}
				break ;
			}
		}
		i++;
	}
}

int	start_dinner(t_param *param)
{
	pid_t			*pids;
	pthread_t		monitor;

	pids = (pid_t *)malloc(sizeof(pid_t) * param->number_philosophers);
	while (param->starting_number <= param->number_philosophers)
	{
		pids[param->starting_number - 1] = fork();
		if (pids[param->starting_number - 1] < 0)
			exit(EXIT_FAILURE);
		if (pids[param->starting_number - 1] == CHILD)
		{
			if (pthread_create(&monitor, NULL, monitoring, param))
				return (EXIT_FAILURE);
			pthread_detach(monitor);
			start_lyfecycle(param);
		}
		else
			param->starting_number++;
	}
	waits(param, pids);
	free(pids);
	return (EXIT_SUCCESS);
}
