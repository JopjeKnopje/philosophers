/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 23:19:20 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include "timer.h"
#include <pthread.h>
#include <stdio.h>

void philo_set_status(t_philo *p, t_status status)
{
	p->status = status;

	pthread_mutex_lock(&p->meta->print_mutex);
	printf(LOG_TEXT[status], timer_delta(p->meta->clock, false), p->id);
	pthread_mutex_unlock(&p->meta->print_mutex);
}
