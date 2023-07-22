/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.c                                           :+:    :+:             */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:16:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 00:02:56 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
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
	t->start = get_time();
	return (t->start);
}

unsigned long	timer_stop(t_timer *t)
{
	t->end = get_time();
	return (t->end);
}

unsigned long	timer_delta(t_timer *t, bool stop)
{
	if (stop)
		t->delta = timer_stop(t) - t->start;
	else 
		return (get_time() - t->start);
	return (t->delta);
}
