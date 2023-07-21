/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/20 16:54:47 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/21 13:42:46 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void monitor(t_meta *meta)
{
	uint32_t	LOOPS = 6;

	uint32_t	i;
	uint32_t	parity = 0;
	t_philo		*p;

	timer_start(meta->timer_sim);

	while (LOOPS) 
	{
		i = 0;
		while (i < meta->philo_count)
		{
			p = meta->philos[i];
			if (p && philo_is_dead(p, meta->timer_sim, meta->time_to_die))
			{
				philo_destroy(p);
				meta->philos[i] = NULL;
			}
			i++;
		}
		printf("\n");
		LOOPS--;
	}
}

