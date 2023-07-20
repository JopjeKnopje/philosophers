/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.c                                           :+:    :+:             */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:16:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/20 15:34:49 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"
#include <sys/time.h>

t_timer *timer_init()
{
	t_timer	*t;

	t = ft_calloc(1, sizeof(t_timer));
	if (!t)
		return (NULL);
	return (t);
}

void	timer_free(t_timer *t)
{
	free(t);
}

unsigned long	timer_start(t_timer *t)
{
	t_timeval tv;
	gettimeofday(&tv, NULL);
	t->start = ((tv.tv_sec * MICRO_TO_SECOND) + tv.tv_usec);
	return (t->start);
}

unsigned long	timer_stop(t_timer *t)
{
	t_timeval tv;
	gettimeofday(&tv, NULL);
	t->end = ((tv.tv_sec * MICRO_TO_SECOND) + tv.tv_usec);
	return (t->end);
}

unsigned long	timer_delta(t_timer *t, bool stop)
{
	if (stop)
	{
		timer_stop(t);
		t->delta = t->end - t->start;
	}
	else 
		t->delta = get_time() - t->start;
			
	return (t->delta);
}
