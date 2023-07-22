/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 23:47:14 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include "timer.h"
#include <stdint.h>
#include <stdio.h>



void monitor(t_meta *meta)
{
	t_timer *t = timer_init();
	uint32_t i;
	t_philo *p;
	
	timer_start(t);
	while (timer_delta(t, false) >= 1000000)
	{
		// check all threads, and join them if philo is dead.
		i = 0;
		while (i < meta->args.philo_count)
		{
			p = meta->philos[i];
			if (p->status == STATUS_DEAD)
			{
				thread_destroy(meta->threads[i]);
			}
			i++;
		}
	}
	timer_free(t);
}
