/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   meuk.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/28 23:34:21 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/13 15:55:20 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void print_philo(t_philo *p)
{
	printf("id: %d | fork left %d | fork right %d\n", p->id, p->forks[PHILO_FORK_LEFT]->id, p->forks[PHILO_FORK_RIGHT]->id);
}

void print_philos(t_philo *ps[], uint32_t count)
{
	int i = 0;
	t_philo *p = ps[i];

	while (i < count)
	{
		p = ps[i];
		i++;
		print_philo(p);
	}
}

void free_philos(t_meta *meta)
{
	uint32_t i = 0;

	while (i < meta->args.philo_count)
	{
		philo_join(meta->philos[i]);
		i++;
	}
	free(meta->philos);
}
