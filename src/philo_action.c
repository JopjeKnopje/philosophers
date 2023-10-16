/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/16 13:08:50 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <assert.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// TODO Make a structure that has a mutex paired with a field
static void philo_update_eat_time(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_eat);
	p->last_eat_time = get_time_ms();
	pthread_mutex_unlock(&p->mutex_eat);
}

static void philo_update_eat_count(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_eat_count);
	p->eat_count++;
	pthread_mutex_unlock(&p->mutex_eat_count);
}

static void philo_eat_single(t_philo *p)
{
	pthread_mutex_lock(&p->forks[PHILO_FORK_LEFT]->mutex);
	logger_log(p, MESSAGE_FORK);

}

static void philo_eat(t_philo *p)
{
	if (p->meta->args.philo_count == 1)
		return philo_eat_single(p);


	pthread_mutex_lock(&p->forks[PHILO_FORK_LEFT]->mutex);
	logger_log(p, MESSAGE_FORK);

	pthread_mutex_lock(&p->forks[PHILO_FORK_RIGHT]->mutex);
	logger_log(p, MESSAGE_FORK);

	logger_log(p, MESSAGE_EAT);
	philo_update_eat_time(p);
	sleep_ms(p->meta->args.time_to_eat);

	philo_update_eat_count(p);

	pthread_mutex_unlock(&p->forks[PHILO_FORK_LEFT]->mutex);
	pthread_mutex_unlock(&p->forks[PHILO_FORK_RIGHT]->mutex);
}

static void philo_sleep(t_philo *p)
{
	logger_log(p, MESSAGE_SLEEP);
	sleep_ms(p->meta->args.time_to_sleep);
}

static void	philo_think(t_philo *p)
{
	int32_t	time_to_think;

	pthread_mutex_lock(&p->mutex_eat);
	time_to_think = (p->meta->args.time_to_die - (get_time_ms() - p->last_eat_time) - p->meta->args.time_to_eat) / 3;
	pthread_mutex_unlock(&p->mutex_eat);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think > 600)
		time_to_think = 200;
	logger_log(p, MESSAGE_THINK);
	sleep_ms(time_to_think);
}

static void	philo_think2(t_philo *p)
{
	logger_log(p, MESSAGE_THINK);
}


void *philo_main(void *arg)
{
	t_philo *p = arg;
	void (*think_func)(t_philo *);

	if (p->meta->args.philo_count % 2)
		think_func = philo_think;
	else 
		think_func = philo_think2;


	philo_update_eat_time(p);
	pthread_mutex_lock(&p->meta->mutex_start);
	pthread_mutex_unlock(&p->meta->mutex_start);
	if (p->id % 2)
		usleep(100);

	while (!sim_get_stop(p->meta))
	{
		(*think_func)(p);
		philo_eat(p);
		philo_sleep(p);
	}
	return (p);
}
