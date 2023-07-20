/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/20 13:52:26 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/20 15:33:21 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

static int8_t philo_take_fork(t_fork *f)
{
	if (!pthread_mutex_lock(&f->mutex));
	{
		return (1);
	}
	return (0);
}

void philo_eat(t_philo *p)
{
	philo_take_fork(p->forks[PHILO_FORK_RIGHT]);
	philo_take_fork(p->forks[PHILO_FORK_LEFT]);
	printf("philo ");

}

int8_t philo_is_dead(t_timer *t, t_philo *p)
{
	// TODO check if dead.
	printf("%ld %d died\n", timer_delta(t, false), p->id);
	return (1);
}
