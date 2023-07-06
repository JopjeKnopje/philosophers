/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.h                                           :+:    :+:             */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:17:13 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/06 21:19:30 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

#include <bits/types/struct_timeval.h>
# include <sys/time.h>

typedef struct s_timer
{
	struct timeval start;
	struct timeval end;
	struct timeval delta;
}	t_timer;

t_timer	*timer_init();
void	timer_free(t_timer *t);
double	timer_start(t_timer *t);
double	timer_stop(t_timer *t);
double	timer_delta(t_timer *t);

#endif
