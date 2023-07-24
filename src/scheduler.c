/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   scheduler.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/23 19:01:40 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/24 10:46:43 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "meta.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

static void scheduler_cycle_active_group(t_scheduler *s)
{
	t_group g;
	
	g = scheduler_get_active_group(s);

	pthread_mutex_lock(&s->group_mutex);
	s->group_active = (g + 1) % 3;
	pthread_mutex_unlock(&s->group_mutex);
}

t_group scheduler_get_active_group(t_scheduler *s)
{
	t_group g;

	pthread_mutex_lock(&s->group_mutex);
	g = s->group_active;
	pthread_mutex_unlock(&s->group_mutex);
	return (g);
}


uint32_t scheduler_get_remaining(t_scheduler *s)
{
	uint32_t r;
	pthread_mutex_lock(&s->mutex);
	r = s->remaining;
	pthread_mutex_unlock(&s->mutex);
	return (r);
}

void scheduler_done(t_meta *m, t_scheduler *s)
{
	bool cycle;
	t_group g;
	
	g = scheduler_get_active_group(s);

	cycle = false;
	pthread_mutex_lock(&s->mutex);
	if (s->remaining - 1 == UINT32_MAX)
		s->remaining = 0;
	else 
		s->remaining--;
	if (!s->remaining)
	{
		cycle = true;
		g = (g + 1) % 3;
		if (g == GROUP_LAST)
			s->remaining = 1;
		else 
			s->remaining = (m->args.philo_count / 2);
	}
	pthread_mutex_unlock(&s->mutex);
	if (cycle)
		scheduler_cycle_active_group(s);
}

