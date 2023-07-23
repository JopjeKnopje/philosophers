/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 19:36:06 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include "timer.h"
#include <pthread.h>
#include <stdio.h>

void philo_set_status(t_philo *p, t_status status)
{
	long time;

	pthread_mutex_lock(&p->meta->status_mutex);
	time = timer_delta(p->meta->clock, false);
	p->status = status;
	printf(LOG_TEXT[status], time, p->id);
	pthread_mutex_unlock(&p->meta->status_mutex);
}

t_status philo_get_status(t_philo *p)
{
	t_status s;
	pthread_mutex_lock(&p->meta->status_mutex);
	s = p->status;
	pthread_mutex_unlock(&p->meta->status_mutex);
	return (s);
}

void philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->forks[PHILO_FORK_LEFT]->mutex);
	philo_set_status(p, STATUS_FORK);
	pthread_mutex_lock(&p->forks[PHILO_FORK_RIGHT]->mutex);
	philo_set_status(p, STATUS_FORK);


	philo_set_status(p, STATUS_EAT);
	timer_start(p->eat_timer);

	sleep_ms(p->meta->args.time_to_eat);

	pthread_mutex_unlock(&p->forks[PHILO_FORK_LEFT]->mutex);
	pthread_mutex_unlock(&p->forks[PHILO_FORK_RIGHT]->mutex);

	scheduler_done(p->meta, &p->meta->scheduler);


	if (timer_delta(p->eat_timer, true) >= p->meta->args.time_to_die)
	{
		philo_set_status(p, STATUS_DEAD);
	}
}
