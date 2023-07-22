/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_action.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 22:00:15 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 22:28:55 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include "timer.h"
#include <stdio.h>

void philo_set_status(t_philo *p, t_status status)
{
	p->status = status;
	// printf("status = %d\n", status);
	// printf(LOG_TEXT[status], timer_delta(p->meta->clock, false), p->id);
}
