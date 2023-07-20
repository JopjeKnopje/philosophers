/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   thread.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/29 16:18:14 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/20 13:28:46 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include "philo.h"

pthread_t *thread_init(t_meta *meta, void *(*routine)(void *), void *arg)
{
	pthread_t *thread;

	thread = ft_calloc(sizeof(pthread_t), 1);


	if (pthread_create(thread, NULL, routine, arg))
	{
		free(thread);
		return (NULL);
	}
	return (thread);
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
	pthread_join(*t, NULL);
	free(t);
}
