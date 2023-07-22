/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 23:58:03 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include "timer.h"
#include <stdint.h>
#include <stdio.h>



void monitor(t_meta *meta)
{
	uint32_t i;
	t_philo *p;
	uint32_t t_count = meta->args.philo_count;
	
	while (t_count)
	{
		i = 0;
		while (i < meta->args.philo_count)
		{
			p = meta->philos[i];
			pthread_mutex_lock(&p->meta->print_mutex);
			t_status s = p->status;
			pthread_mutex_unlock(&p->meta->print_mutex);
			if (s)
			{
				thread_destroy(meta->threads[i]);
				t_count--;
			}
			i++;
		}
	}
}
