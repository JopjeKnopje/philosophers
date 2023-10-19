/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   simulation.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: jboeve <jboeve@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/10/19 16:12:27 by jboeve        #+#    #+#                 */
/*   Updated: 2023/10/19 16:22:37 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdio.h>
#include <unistd.h>

static int free_mutexes(void *arr, size_t len)
{
	pthread_mutex_t *ptr = arr;
	size_t i = 0;

	while (i < len)
	{
		pthread_mutex_destroy(&arr[i]);
		i++;
	}
	return 0;
}

static int init_mutexes(void *arr, size_t len)
{
	pthread_mutex_t *ptr = arr;
	size_t i = 0;

	while (i < len)
	{
		if (pthread_mutex_init(&arr[i], NULL))
		{
			free_mutexes(arr, i);
			return 1;
		}
		i++;
	}
	return 0;
}

int sim_start(t_meta *meta)
{
	if (init_mutexes(&meta->mutex_log, 3))
		return (0);
	if (forks_init(meta, meta->args.philo_count))
	{
		free_mutexes(&meta->mutex_log, 3);
		return (0);
	}
	if (philos_init(meta, meta->args.philo_count))
	{
		printf("philos_init failed\n");
		free_mutexes(&meta->mutex_log, 3);
		free_forks(meta);
		return (0);
	}

	meta->start_time = get_time_ms();
	pthread_mutex_unlock(&meta->mutex_sync);
	usleep(1);
	monitor(meta);
	return (1);
}

void sim_set_stop(t_meta *meta)
{
	pthread_mutex_lock(&meta->mutex_running);
	meta->sim_stop = true;
	pthread_mutex_unlock(&meta->mutex_running);
}

bool sim_get_stop(t_meta *meta)
{
	bool	running;

	// TODO Remote mutex
	pthread_mutex_lock(&meta->mutex_running);
	running = meta->sim_stop;
	pthread_mutex_unlock(&meta->mutex_running);
	return (running);
}

int sim_cleanup(t_meta *meta)
{
	free_philos(meta);
	free_forks(meta);

	if (pthread_mutex_destroy(&meta->mutex_sync))
		return (0);
	if (pthread_mutex_destroy(&meta->mutex_log))
		return (0);
	if (pthread_mutex_destroy(&meta->mutex_running))
		return (0);
	return (1);
}
