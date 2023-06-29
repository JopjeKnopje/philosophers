/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:34:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/29 16:36:26 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>
#include <stdlib.h>

t_philo *philo_init(t_fork *forks[], uint32_t count, uint32_t id)
{
	t_philo *p;

	p = ft_calloc(sizeof(t_philo), 1);
	if (!p)
		return (NULL);
	p->id = id;
	p->status = STATUS_NONE;
	p->forks[FORK_LEFT] = forks[id];
	p->forks[FORK_RIGHT] = forks[(id + 1) % count];
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

void	philo_destroy(t_philo *p)
{
	free(p->forks);
}
