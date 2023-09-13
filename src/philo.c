/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:34:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/13 16:00:10 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "meta.h"

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
	if (pthread_create(&p->thread, NULL, philo_main, p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

int8_t	philos_init(t_meta *meta, uint32_t count)
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


	// take 2 forks
	// eat with eat_time
	// sleep for sleep_time
	// think until forks are available

	for (int i = 0; i < 10; i++)
	{
		printf("pid: %d | i: %d\n", p->id, i);
		sleep_ms(50);
	}


	return (p);
}

void	philo_join(t_philo *p)
{
	pthread_join(p->thread, (void *) p);
	printf("joined %d\n", p->id);
	free(p);
}
