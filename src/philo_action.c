/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/20 13:52:26 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/21 13:13:57 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

static void philo_eat(t_philo *p)
{
	timer_start(p->timer);
	// TODO Log
}

void *philo_routine(void *arg)
{
	t_philo *philo = arg;

	// print_philo(philo);
	
	return (NULL);
}
