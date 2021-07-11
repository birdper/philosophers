#include "philo_three.h"

void	unlink_semaphors(void)
{
	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
}
