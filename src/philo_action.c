/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/17 00:37:16 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void philo_eat(t_philo *p)
{
	// eat
	pthread_mutex_lock(&p->forks[PHILO_FORK_LEFT]->mutex);
	logger_log(p, MESSAGE_FORK);

	pthread_mutex_lock(&p->forks[PHILO_FORK_RIGHT]->mutex);
	logger_log(p, MESSAGE_FORK);

	logger_log(p, MESSAGE_EAT);
	p->last_eat_time = get_time_ms();
	printf("pid %u | last_eat_time: %lu\n",p->id, get_time_ms() - p->last_eat_time);
	sleep_ms(p->meta->args.time_to_eat);
	pthread_mutex_unlock(&p->forks[PHILO_FORK_LEFT]->mutex);
	pthread_mutex_unlock(&p->forks[PHILO_FORK_RIGHT]->mutex);
}

void philo_sleep(t_philo *p)
{
	logger_log(p, MESSAGE_SLEEP);
	sleep_ms(p->meta->args.time_to_sleep);
}

void philo_think(t_philo *p)
{
	logger_log(p, MESSAGE_THINK);
}
