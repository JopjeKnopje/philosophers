/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   forks.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/26 18:17:25 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/28 18:50:57 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static t_fork	*fork_init(uint32_t id)
{
	t_fork	*f;
	f = ft_calloc(sizeof(t_fork), 1);
	if (!f)
		return (NULL);
	if (pthread_mutex_init(&f->mutex, NULL))
		return (NULL);
	f->id = id;
	return (f);
}

int8_t	forks_init(t_meta *meta, size_t count)
{
	uint32_t

	i = 0;
	meta->forks = ft_calloc(sizeof(t_fork *), count);
	if (!meta->forks)
		return (1);
	while (i < count)
	{
		meta->forks[i] = fork_init(i);
		if (!meta->forks[i])
			return (1);
		i++;
	}
	return (0);
}

void free_forks(t_meta *meta)
{
	uint32_t i = 0;
	
	while (i < meta->philo_count)
	{
		pthread_mutex_destroy(&meta->forks[i]->mutex);
		free(meta->forks[i]);
		i++;
	}
	free(meta->forks);
}
