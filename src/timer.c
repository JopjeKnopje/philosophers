/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.c                                           :+:    :+:             */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:16:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/06 23:49:15 by joppe         ########   odam.nl         */
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

t_timeval	*timer_start(t_timer *t)
{
	gettimeofday(&t->start, NULL);
	return (&t->start);
}

t_timeval	*timer_stop(t_timer *t)
{
	gettimeofday(&t->end, NULL);
	return (&t->end);
}

t_timeval	*timer_delta(t_timer *t)
{
	timer_stop(t);
	t->delta.tv_sec = t->end.tv_sec - t->start.tv_sec;
	t->delta.tv_usec = t->end.tv_usec - t->start.tv_usec;
	return (&t->delta);
}
