/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.h                                           :+:    :+:             */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:17:13 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/06 23:49:07 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

#include <bits/types/struct_timeval.h>
# include <sys/time.h>

typedef struct timeval t_timeval;

typedef struct s_timer
{
	t_timeval start;
	t_timeval end;
	t_timeval delta;
}	t_timer;

t_timer	*timer_init();
void	timer_free(t_timer *t);
t_timeval	*timer_start(t_timer *t);
t_timeval	*timer_stop(t_timer *t);
t_timeval	*timer_delta(t_timer *t);

#endif
