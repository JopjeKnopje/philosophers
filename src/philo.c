/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:34:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 21:33:58 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "meta.h"

static t_philo *philo_init(t_fork *forks[], uint32_t count, uint32_t id)
{
	t_philo *p;

	p = ft_calloc(sizeof(t_philo), 1);
	if (!p)
		return (NULL);
	p->id = id + 1;
	p->status = STATUS_NONE;
	p->forks[PHILO_FORK_LEFT] = forks[id];
	p->forks[PHILO_FORK_RIGHT] = forks[(id + 1) % count];
	p->timer = timer_init();
	timer_start(p->timer);
	return (p);
}

int8_t	philos_init(t_meta *meta, uint32_t count)
{
	uint32_t	i;

	i = 0;
	meta->philos = ft_calloc(sizeof(t_philo *), count);
	if (!meta->philos)
		return (1);
	while (i < count)
	{
		meta->philos[i] = philo_init(meta->forks, count, i);
		if (!meta->philos[i])
			return (1);
		i++;
	}
	return (0);
}

void *philo_main(void *arg)
{
	t_philo *p = arg;

		printf("hello form philo %d\n", p->id);
	return p;
}

void	philo_destroy(t_philo *p)
{
	free(p->timer);
	free(p->forks);
}

void	philo_destroy1(t_philo1 *ptr)
{
	t_philo *p = ptr;
	free(p->timer);
	free(p->forks);
}
