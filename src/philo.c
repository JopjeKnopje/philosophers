/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:34:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/14 00:33:49 by joppe         ########   odam.nl         */
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

static t_philo *philo_init(t_philo *p, t_meta *meta, uint32_t i)
{
	p->meta = meta;
	p->id = i + 1;
	p->forks[PHILO_FORK_LEFT] = &meta->forks[i];
	p->forks[PHILO_FORK_RIGHT] = &meta->forks[(i + 1) % meta->args.philo_count];
	philo_swap_forks(p);

	if (pthread_mutex_init(&p->mutex_meal, NULL))
		return (NULL);
	if (pthread_create(&p->thread, NULL, philo_main, p))
	{
		pthread_mutex_destroy(&p->mutex_meal);
		return (NULL);
	}
	return (p);
}

int	philos_init(t_meta *meta, uint32_t count)
{
	int32_t	i;

	i = 0;
	meta->philos = ft_calloc(sizeof(t_philo), count);
	if (!meta->philos)
		return (0);

	while (i < meta->args.philo_count)
	{
		if (!philo_init(&meta->philos[i], meta, i))
		{
			free(meta->philos);
			return (1);
		}
		i++;
	}
	return (0);
}

void	philo_join(t_philo *p)
{
	pthread_join(p->thread, (void *) p);
}
