/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_probe.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: jboeve <marvin@42.fr>                       +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/21 11:28:32 by jboeve        #+#    #+#                 */
/*   Updated: 2023/07/21 13:37:19 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int8_t philo_is_dead(t_philo *p, t_timer *sim_timer, uint32_t time_to_die)
{
	long delta;
	int8_t is_dead;

	delta = timer_delta(p->timer, false);

	is_dead = (delta > time_to_die);
	if (is_dead)
		philo_set_status(p, sim_timer, STATUS_DEAD);
	return (is_dead);
}
