/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   thread.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/29 16:18:14 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 01:27:41 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "meta.h"

pthread_t *thread_init(t_meta *meta, void *(*routine)(void *), void *arg)
{
	pthread_t *t;

	t = ft_calloc(sizeof(pthread_t), 1);

	if (pthread_create(t, NULL, routine, arg))
	{
		free(t);
		return (NULL);
	}
	return (t);
}

int8_t	threads_init(t_meta *meta, void *(*routine)(void *), uint32_t count)
{
	uint32_t	i;

	i = 0;
	meta->threads = ft_calloc(sizeof(t_philo *), count);
	if (!meta->threads)
		return (1);
	while (i < count)
	{
		meta->threads[i] = thread_init(meta, routine, meta->philos[i]);
		if (!meta->threads[i])
			return (1);
		i++;
	}
	return (0);
}

void	thread_destroy(pthread_t *t)
{
	t_philo *p;
	pthread_join(*t, (void **) &p);
	// printf("joined id %d\n", p->id);
	free(t);
}
