/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   free.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/28 18:52:05 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/24 15:10:14 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stddef.h>
#include <stdint.h>

// TODO Abstract free func.
void	free_philos(t_philo *philos, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		philo_join(&philos[i]);
		i++;
	}
	free(philos);
}

void	free_forks(t_fork *forks, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		fork_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

int	free_mutexes(pthread_mutex_t *arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		pthread_mutex_destroy(&arr[i]);
		i++;
	}
	return (0);
}
