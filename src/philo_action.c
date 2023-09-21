/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/21 16:15:12 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void philo_update_eat_time(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_meal);
	p->last_eat_time = get_time_ms();
	pthread_mutex_unlock(&p->mutex_meal);
}

static void philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->forks[PHILO_FORK_LEFT]->mutex);
	logger_log(p, MESSAGE_FORK);

	pthread_mutex_lock(&p->forks[PHILO_FORK_RIGHT]->mutex);
	logger_log(p, MESSAGE_FORK);

	logger_log(p, MESSAGE_EAT);
	philo_update_eat_time(p);
	sleep_ms(p->meta->args.time_to_eat);

	pthread_mutex_unlock(&p->forks[PHILO_FORK_LEFT]->mutex);
	pthread_mutex_unlock(&p->forks[PHILO_FORK_RIGHT]->mutex);
}

static void philo_sleep(t_philo *p)
{
	logger_log(p, MESSAGE_SLEEP);
	sleep_ms(p->meta->args.time_to_sleep);
}

static void philo_think(t_philo *p)
{
	logger_log(p, MESSAGE_THINK);
}

void *philo_main(void *arg)
{
	t_philo *p = arg;

	philo_update_eat_time(p);
	pthread_mutex_lock(&p->meta->mutex_start);
	pthread_mutex_unlock(&p->meta->mutex_start);

	while (!sim_get_stop(p->meta))
	{
		philo_think(p);
		philo_eat(p);
		philo_sleep(p);
	}
	return (p);
}
