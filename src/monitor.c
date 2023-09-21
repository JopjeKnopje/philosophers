/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/20 12:56:11 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

static bool has_died(t_philo *p)
{
	bool val;

	pthread_mutex_lock(&p->mutex_meal);
	val = (get_time_ms() - p->last_eat_time >= p->meta->args.time_to_die);
	pthread_mutex_unlock(&p->mutex_meal);
	return val;
}

static bool monitor_loop(t_meta *meta)
{
	size_t	i; 
	t_philo	*p;

	i = 0;
	while (i < meta->args.philo_count)
	{
		p = meta->philos[i];
		if (has_died(p))
		{
			sim_stop(p->meta);
			logger_log(p, MESSAGE_DEAD);
			dup2
			return (false);
		}
		i++;
	}
	return (true);
}

void *monitor(t_meta *meta)
{
	while (1)
	{
		if (!monitor_loop(meta))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
