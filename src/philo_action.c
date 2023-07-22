/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 23:59:22 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include "timer.h"
#include <pthread.h>
#include <stdio.h>

void philo_set_status(t_philo *p, t_status status)
{

	long time = timer_delta(p->meta->clock, false);


	pthread_mutex_lock(&p->meta->print_mutex);
	p->status = status;
	printf(LOG_TEXT[status], time, p->id);
	pthread_mutex_unlock(&p->meta->print_mutex);
}
