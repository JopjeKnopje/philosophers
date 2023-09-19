/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:34:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/19 17:32:00 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "meta.h"

static void philo_swap_forks(t_philo *p)
{
	if (p->id % 2)
	{
		t_fork *tmp = p->forks[PHILO_FORK_LEFT];
		p->forks[PHILO_FORK_LEFT] = p->forks[PHILO_FORK_RIGHT];
		p->forks[PHILO_FORK_RIGHT] = tmp;
	}
}

static t_philo *philo_init(t_fork **forks, t_meta *meta, uint32_t count, uint32_t id)
{
	t_philo	*p;

	p = ft_calloc(sizeof(t_philo), 1);
	if (!p)
		return (NULL);
	p->meta = meta;
	p->id = id + 1;
	p->forks[PHILO_FORK_LEFT] = forks[id];
	p->forks[PHILO_FORK_RIGHT] = forks[(id + 1) % count];
	philo_swap_forks(p);
	if (pthread_mutex_init(&p->mutex_meal, NULL))
	{
		printf("mutex_init failed\n");
		return (NULL);
	}
	if (pthread_create(&p->thread, NULL, philo_main, p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

int	philos_init(t_meta *meta, uint32_t count)
{
	uint32_t	i;

	i = 0;
	meta->philos = ft_calloc(sizeof(t_philo *), count);
	if (!meta->philos)
		return (0);
	while (i < count)
	{
		meta->philos[i] = philo_init(meta->forks, meta, count, i);
		if (!meta->philos[i])
		{
			// TODO When `i != 0` fails free the others.
			return (1);
		}
		i++;
	}
	return (0);
}

void *philo_main(void *arg)
{
	t_philo *p = arg;

	philo_update_eat_time(p);
	pthread_mutex_lock(&p->meta->mutex_start);
	pthread_mutex_unlock(&p->meta->mutex_start);

	while (!sim_should_stop(p->meta))
	{
		philo_think(p);
		philo_eat(p);
		philo_sleep(p);
	}
	return (p);
}

void	philo_join(t_philo *p)
{
	pthread_join(p->thread, (void *) p);
	// printf("joined %d\n", p->id);
	free(p);
}
