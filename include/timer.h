/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timer.h                                           :+:    :+:             */
/*                                                     +:+                    */
/*   By: joppe <jboeve@student.codam.nl>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 09:17:13 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 16:08:18 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include <stdbool.h>

typedef struct timeval t_timeval;

typedef struct s_timer
{
	long start;
	long end;
	long delta;
}	t_timer;

t_timer			*timer_init();
void			timer_free(t_timer *t);
unsigned long	timer_start(t_timer *t);
unsigned long	timer_stop(t_timer *t);
unsigned long	timer_delta(t_timer *t, bool stop);

#endif
