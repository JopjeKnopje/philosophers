/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/21 11:58:50 by jboeve        ########   odam.nl         */
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
			logger_log(p, MESSAGE_DEAD);
			sim_stop(p->meta);
			return (false);
		}
		i++;
	}
	return (true);
}

void *monitor(t_meta *meta)
{
	while (monitor_loop(meta))
		usleep(1000);
	return (NULL);
}
