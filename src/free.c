/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   free.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/28 18:52:05 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/29 16:43:47 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_forks(t_meta *meta)
{
	uint32_t i = 0;
	
	while (i < meta->philo_count)
	{
		fork_destroy(meta->forks[i]);
		i++;
	}
	free(meta->forks);
}

void free_philos(t_meta *meta)
{
	uint32_t i = 0;
	
	while (i < meta->philo_count)
	{
		philo_destroy(meta->philos[i]);
		i++;
	}
	free(meta->philos);
}

void free_threads(t_meta *meta)
{
	uint32_t i = 0;
	
	while (i < meta->philo_count)
	{
		thread_destroy(meta->threads[i]);
		i++;
	}
	free(meta->threads);
}
