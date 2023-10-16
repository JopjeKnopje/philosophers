/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/16 02:25:39 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

static bool has_died(t_philo *p)
{
	bool val;

	pthread_mutex_lock(&p->mutex_eat);
	val = (get_time_ms() - p->last_eat_time >= p->meta->args.time_to_die);
	pthread_mutex_unlock(&p->mutex_eat);
	return val;
}

static bool monitor_loop(t_meta *meta)
{
	const bool monitor_eat = (meta->args.max_eat_count != ARG_NOT_SET);
	int32_t done_eating_count;
	size_t	i; 
	t_philo	*p;

	done_eating_count = 0;
	i = 0;
	while (i < meta->args.philo_count)
	{
		p = &meta->philos[i];
		if (monitor_eat)
		{
			if (philo_get_eat_count(p) >= meta->args.max_eat_count)
				done_eating_count++;
		}
		if (has_died(p))
		{
			logger_log(p, MESSAGE_DEAD);
			sim_set_stop(p->meta);
			return (false);
		}
		i++;
	}
	if (done_eating_count >= meta->args.philo_count)
	{
		sim_set_stop(p->meta);
		return (false);
	}
	return (true);
}

void *monitor(t_meta *meta)
{
	while (monitor_loop(meta))
		usleep(1000);
	return (NULL);
}
