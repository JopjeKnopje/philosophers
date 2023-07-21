/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/20 16:54:47 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/20 17:09:58 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
#include <stdio.h>

static void monitor_philo(t_philo *p)
{
	printf("checking philo %d\n", p->id);
}

void monitor(t_meta *meta)
{
	uint32_t	LOOPS = 10;

	uint32_t	i;
	uint32_t	parity = 0;

	timer_start(meta->timer_sim);

	while (LOOPS) 
	{
		i = 0;
		while (i < (meta->philo_count - (meta->philo_count % 2)))
		{
			monitor_philo(meta->philos[i]);
			i += 2;
		}
		printf("\n");
		i = 1;
		while (i < (meta->philo_count - (meta->philo_count % 2)))
		{
			monitor_philo(meta->philos[i]);
			i += 2;
		}
		printf("\n");
		if (meta->philo_count % 2)
		{
			monitor_philo(meta->philos[meta->philo_count - 1]);
		}

		printf("\n");
		LOOPS--;
	}
}

