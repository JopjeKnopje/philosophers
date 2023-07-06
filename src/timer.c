/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.c                                           :+:    :+:             */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:16:42 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/06 21:19:53 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"

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

double	timer_start(t_timer *t)
{
	t->start = (*t->time_func)();
	return (t->start);
}

double	timer_stop(t_timer *t)
{
	t->end = (*t->time_func)();
	return (t->end);
}

double	timer_delta(t_timer *t)
{
	timer_stop(t);
	t->delta = t->end - t->start;
	return (t->delta);
}
