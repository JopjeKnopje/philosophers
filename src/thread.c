/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   thread.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/29 16:18:14 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/29 17:07:53 by joppe         ########   odam.nl         */
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

void	thread_destroy(pthread_t *t)
{
	pthread_join(*t, NULL);
	free(t);
}
