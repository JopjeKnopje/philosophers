/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 02:30:55 by joppe         ########   odam.nl         */
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

void philo_take_fork(t_philo *p)
{
	pthread_mutex_lock(&p->forks[PHILO_FORK_LEFT]->mutex);
	pthread_mutex_lock(&p->forks[PHILO_FORK_RIGHT]->mutex);
	philo_set_status(p, STATUS_FORK);
}

void philo_putdown_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->forks[PHILO_FORK_RIGHT]->mutex);
	pthread_mutex_unlock(&p->forks[PHILO_FORK_LEFT]->mutex);
	philo_set_status(p, STATUS_THINK);
	timer_start(p->eat_timer);
}
