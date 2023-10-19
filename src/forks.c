/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   forks.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/26 18:17:25 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/19 18:10:08 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static t_fork	*fork_init(t_fork *f, uint32_t id)
{
	if (pthread_mutex_init(&f->mutex, NULL))
		return (NULL);
	f->id = id;
	return (f);
}

int8_t	forks_init(t_meta *meta, size_t count)
{
	uint32_t	i;

	i = 0;
	meta->forks = ft_calloc(sizeof(t_fork), count);
	if (!meta->forks)
		return (1);
	while (i < count)
	{
		if (!fork_init(&meta->forks[i], i))
			return (1);
		i++;
	}
	return (0);
}

void	fork_destroy(t_fork *f)
{
	pthread_mutex_destroy(&f->mutex);
}
