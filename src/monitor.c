/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 16:22:47 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include "timer.h"
#include <stdint.h>
#include <stdio.h>

static void monitor_cycle_active_group(t_meta *meta)
{
	t_group g;
	
	g = monitor_get_active_group(meta);

	pthread_mutex_lock(&meta->group_mutex);
	meta->active_group = (g + 1) % 3;
	pthread_mutex_unlock(&meta->group_mutex);
}

t_group monitor_get_active_group(t_meta *meta)
{
	t_group g;

	pthread_mutex_lock(&meta->group_mutex);
	g = meta->active_group;
	pthread_mutex_unlock(&meta->group_mutex);
	return (g);
}

void monitor(t_meta *meta)
{
	t_philo *p;
	uint32_t i;
	uint32_t t_count;
	
	t_status s;
	t_timer *cycle_timer = timer_init();
	timer_start(cycle_timer);

	t_count = meta->args.philo_count;
	while (t_count)
	{
		i = 0;
		while (i < meta->args.philo_count)
		{
			p = meta->philos[i];
			if (philo_get_status(p) == STATUS_DEAD)
			{
				thread_destroy(meta->threads[i]);
				p->status = STATUS_INACTIVE;
				t_count--;
			}
			i++;
		}
		if (timer_delta(cycle_timer, false) >= 100)
		{
			monitor_cycle_active_group(meta);
			timer_start(cycle_timer);
		}
	}
	timer_free(cycle_timer);
}

