/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   free.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/28 18:52:05 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/19 18:03:29 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdint.h>

void free_forks(t_meta *meta)
{
	int32_t i = 0;
	
	while (i < meta->args.philo_count)
	{
		fork_destroy(&meta->forks[i]);
		i++;
	}
	free(meta->forks);
}

void free_philos(t_meta *meta)
{
	int32_t i = 0;

	while (i < meta->args.philo_count)
	{
		philo_join(&meta->philos[i]);
		i++;
	}
	free(meta->philos);
}

int free_mutexes(pthread_mutex_t *arr, size_t len)
{
	size_t i = 0;

	while (i < len)
	{
		pthread_mutex_destroy(&arr[i]);
		i++;
	}
	return 0;
}

