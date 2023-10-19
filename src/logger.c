/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   logger.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: jboeve <jboeve@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/09/13 16:41:06 by jboeve        #+#    #+#                 */
/*   Updated: 2023/10/19 18:18:45 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <pthread.h>
#include <stdio.h>

static const char	*get_log_msgs(t_message s)
{
	static const char	*log_text[] = {
		"%lu %u has taken a fork\n",
		"%lu %u is eating\n",
		"%lu %u is sleeping\n",
		"%lu %u is thinking\n",
		"%lu %u died\n",
	};

	return (log_text[s]);
}

void	logger_log(t_philo *p, t_message status)
{
	pthread_mutex_lock(&p->meta->mutex_log);
	if (sim_get_stop(p->meta))
	{
		pthread_mutex_unlock(&p->meta->mutex_log);
		return ;
	}
	printf(get_log_msgs(status), get_time_ms() - p->meta->start_time, p->id);
	pthread_mutex_unlock(&p->meta->mutex_log);
}
