/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/17 00:30:54 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>

static void *monitor_loop(t_meta *meta)
{
	size_t i = 0;
	t_philo *p;

	while (i < meta->args.philo_count)
	{
		p = meta->philos[i];
		i++;
	}
	return (void *) 1;
}

void *monitor(t_meta *meta)
{
	while (1)
	{
		if (!monitor_loop(meta))
			break;
	}
	return (NULL);
}
