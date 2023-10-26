/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/26 16:44:50 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdio.h>
#include <unistd.h>

static void	philo_eat(t_philo *p)
{
	pthread_mutex_lock(p->forks[PHILO_FORK_RIGHT]);
	logger_log(p, MESSAGE_FORK);
	pthread_mutex_lock(p->forks[PHILO_FORK_LEFT]);
	logger_log(p, MESSAGE_FORK);
	philo_update_eat_time(p);
	logger_log(p, MESSAGE_EAT);
	sleep_ms(p->meta->args.time_to_eat);
	pthread_mutex_unlock(p->forks[PHILO_FORK_RIGHT]);
	pthread_mutex_unlock(p->forks[PHILO_FORK_LEFT]);
	philo_update_eat_count(p);
}

static void	philo_sleep(t_philo *p)
{
	logger_log(p, MESSAGE_SLEEP);
	sleep_ms(p->meta->args.time_to_sleep);
}

static void	philo_think(t_philo *p)
{
	const int32_t	ttd = p->meta->args.time_to_die;
	const int32_t	ttt = p->meta->args.time_to_eat;
	int32_t			time_to_think;

	pthread_mutex_lock(&p->mutex_eat_time);
	time_to_think = (ttd - (get_time_ms() - p->last_eat_time) - ttt) / 3;
	pthread_mutex_unlock(&p->mutex_eat_time);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think > 600)
		time_to_think = 200;
	logger_log(p, MESSAGE_THINK);
	sleep_ms(time_to_think);
}

static void	philo_thonk(t_philo *p)
{
	logger_log(p, MESSAGE_THINK);
}

void	*philo_main(void *arg)
{
	t_philo			*p;
	t_think_func	func;

	p = arg;
	func = philo_set_fun(p, philo_think, philo_thonk);
	// func = philo_thonk;

	pthread_mutex_lock(&p->meta->mutex_sync);
	pthread_mutex_unlock(&p->meta->mutex_sync);

	if (p->meta->philo_failed)
		return (NULL);
	if (p->id % 2)
		usleep(100);
	if (p->meta->args.philo_count == 1)
	{
		logger_log(p, MESSAGE_FORK);
		return (p);
	}
	while (!sim_get_stop(p->meta))
	{
		(*func)(p);
		philo_eat(p);
		philo_sleep(p);
	}
	return (p);
}
