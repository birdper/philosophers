#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	pthread_t			pthread;
	int					time_last_meal;
	int					times_eat;
}	t_philosopher;

typedef struct s_param
{
	int					number_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;
	long				starting_point;
	int					starting_number;
	int					alive;
	sem_t				*forks_sem;
	sem_t				*print_sem;
	t_philosopher		*phil;
}	t_param;

int			parse(int argc, char **argv, t_param *param);
int			start_dinner(t_param *param, t_philosopher *philosophers,
				pthread_t *monitor);
void		*monitoring(void *par);

void		print_status(char *msg_status, int number_philosopher, int d_time);
long		get_currenttime_ms(void);
int			get_passedtime(long starting_point);
void		print_with_lock(char *msg, int d_number, t_param *param);
void		stage(int desire_time_ms);

int			ft_isdigit(int c);
int			is_notnumber(char *arg);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int32_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
