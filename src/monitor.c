/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/08/29 19:01:01 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdint.h>
#include <stdio.h>

void monitor(t_meta *meta)
{
	t_philo *p;
	uint32_t i;
	uint32_t t_count;
	
	t_status s;

	t_count = meta->args.philo_count;
	while (t_count)
	{
		i = 0;
		while (i < meta->args.philo_count)
		{
			p = meta->philos[i];
			if (philo_get_status(p) == STATUS_DEAD)
			{
				thread_destroy(meta->threads[i]);
				t_count--;
			}
			i++;
		}
	}
}

