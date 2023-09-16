/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/17 01:43:24 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

static bool has_died(t_philo *p)
{
	bool val;

	pthread_mutex_lock(&p->mutex_meal);
	val = (p->meta->args.time_to_die < get_time_ms() - p->last_eat_time);
	pthread_mutex_unlock(&p->mutex_meal);
	return val;
}

static void *monitor_loop(t_meta *meta)
{
	size_t i = 0;
	t_philo *p;

	while (i < meta->args.philo_count)
	{
		p = meta->philos[i];

		if (has_died(p))
		{
			printf("pid [%u] | killed\n", p->id);
			// philo_join(p);
		}
		i++;
	}
	return (void *) 1;
}

void *monitor(t_meta *meta)
{
	while (1)
	{
		if (!monitor_loop(meta))
			break;
	}
	return (NULL);
}
