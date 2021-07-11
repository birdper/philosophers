#include "philo_two.h"

void	print_status(char *msg_status, int number_philosopher, int d_time)
{
	char	*str_time;
	char	*str_number;
	char	*res;
	int		len;

	str_time = ft_itoa(d_time);
	str_number = ft_itoa(number_philosopher);
	len = ft_strlen(str_time) + ft_strlen(str_number)
		  + ft_strlen(msg_status) + 2;
	res = (char *)malloc(sizeof(char) * (len + 1));
	*res = '\0';
	ft_strlcat(res, str_time, len + 1);
	ft_strlcat(res, " ", len + 1);
	ft_strlcat(res, str_number, len + 1);
	ft_strlcat(res, msg_status, len + 1);
	ft_strlcat(res, "\n", len + 1);
	write(1, res, len);
	free(res);
	free(str_number);
	free(str_time);
}

long	get_currenttime_ms(void)
{
	struct timeval		present_point;

	gettimeofday(&present_point, NULL);
	return (present_point.tv_usec / 1000 + present_point.tv_sec * 1000);
}

int	get_passedtime(long starting_point)
{
	return ((int)(get_currenttime_ms() - starting_point));
}

void	print_with_lock(char *msg, int d_number, t_param *param)
{
	sem_wait(param->print_sem);
	print_status(msg, d_number, get_passedtime(param->starting_point));
	sem_post(param->print_sem);
}

void	stage(int desire_time_ms)
{
	long		starting_point;

	starting_point = get_currenttime_ms();
	while (1)
	{
		if (get_currenttime_ms() - starting_point >= desire_time_ms)
			return ;
		usleep(60);
	}
}
