/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/20 13:52:26 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/21 11:10:41 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

static int8_t philo_take_fork(t_fork *f)
{
	if (!pthread_mutex_lock(&f->mutex))
	{
		return (1);
	}
	return (0);
}

void philo_eat(t_philo *p)
{
	// philo_take_fork(p->forks[PHILO_FORK_RIGHT]);
	// philo_take_fork(p->forks[PHILO_FORK_LEFT]);
	timer_start(p->timer);
}

int8_t philo_is_dead(t_timer *sim_timer, t_philo *p)
{
	// TODO check if dead.
	long delta;

	delta = timer_delta(t, false);
	if (delta > meta.)
	printf("%ld %d died\n", delta, p->id);
	return (1);
}
