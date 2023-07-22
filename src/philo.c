/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:34:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 00:55:11 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "meta.h"

static t_philo *philo_init(t_fork **forks, t_meta *meta, uint32_t count, uint32_t id)
{
	t_philo *p;

	p = ft_calloc(sizeof(t_philo), 1);
	if (!p)
		return (NULL);
	p->meta = meta;
	p->id = id + 1;
	p->status = STATUS_INACTIVE;
	p->forks[PHILO_FORK_LEFT] = forks[id];
	p->forks[PHILO_FORK_RIGHT] = forks[(id + 1) % count];
	p->eat_timer = timer_init();
	timer_start(p->eat_timer);
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
		meta->philos[i] = philo_init(meta->forks, meta, count, i);
		if (!meta->philos[i])
			return (1);
		i++;
	}
	return (0);
}

void *philo_main(void *arg)
{
	t_philo *p = arg;

	pthread_mutex_lock(&p->meta->start_mutex);
	pthread_mutex_unlock(&p->meta->start_mutex);

	while (p->status != STATUS_DEAD) 
	{
		if (timer_delta(p->eat_timer, false) >= p->meta->args.eat_threshold)
		{
			philo_set_status(p, STATUS_DEAD);
			break;
		}
	}
	uint32_t *id = ft_calloc(sizeof(uint32_t), 1);
	*id = p->id;
	// return (p);
	return (id);
}

void	philo_destroy(t_philo *p)
{
	free(p->eat_timer);
	free(p);
}
