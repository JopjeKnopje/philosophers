/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/20 13:52:26 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/20 13:55:08 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void philo_eat(t_philo *p)
{


	// if (pthread_create(thread, NULL, routine, arg))
	pthread_mutex_lock(&p->forks[PHILO_FORK_LEFT]->mutex);
	pthread_mutex_lock(&p->forks[PHILO_FORK_RIGHT]->mutex);
	printf("philo ")
	

}

