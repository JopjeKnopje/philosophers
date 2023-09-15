/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   logger.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: jboeve <jboeve@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/09/13 16:41:06 by jboeve        #+#    #+#                 */
/*   Updated: 2023/09/15 16:46:14 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <pthread.h>
#include <stdio.h>

static const char *LOG_TEXT[] = {
	"%ld %d has taken a fork\n",
	"%ld %d is eating\n",
	"%ld %d is sleeping\n",
	"%ld %d is thinking\n",
	"%ld %d died\n",
};


int logger_init(t_meta *meta)
{
	if (pthread_mutex_init(&meta->mutex_log, NULL))
	{
		printf("failed to init mutex\n");
		return (0);
	}
	meta->start_time = get_time_ms();
	return (1);
}

void logger_log(t_philo *p, t_message status)
{
	printf(LOG_TEXT[status], (get_time_ms() - p->meta->start_time),  p->id);
}

