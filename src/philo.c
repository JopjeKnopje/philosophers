/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:34:12 by joppe         #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2023/07/19 18:37:01 by joppe         ########   odam.nl         */
=======
/*   Updated: 2023/07/21 13:41:09 by jboeve        ########   odam.nl         */
>>>>>>> 3abb4be07f3eb7c718eeebf66c9b9182e704da94
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "timer.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

t_philo *philo_init(t_fork *forks[], uint32_t count, uint32_t id)
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

void philo_set_status(t_philo *p, t_timer *sim_timer, t_status s)
{
	p->status = s;
	printf(LOG_TEXT[s], timer_delta(sim_timer, false), p->id);
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

void	philo_destroy(t_philo *p)
{
	free(p->timer);
	free(p->forks);
}


