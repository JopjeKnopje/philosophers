/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/29 17:08:18 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

#define FORK_COUNT 5

void *routine(void *arg)
{
	t_philo *philo = arg;

	int i = 0;
	while (i < 10000)
	{
		printf("i: %d\n", i);
		i++;
	}
	// print_philo(philo);
	printf("done\n");
	
	return (NULL);
}

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.philo_count = FORK_COUNT;
	forks_init(&meta, meta.philo_count);
	philos_init(&meta, meta.philo_count);

	// print_philos(meta.philos, meta.philo_count);

	int i = 0;
	meta.threads = ft_calloc(sizeof(pthread_t *), meta.philo_count);
	while (i < meta.philo_count)
	{
		meta.threads[i] = thread_init(&meta, &routine, &meta.philos[i]);
		if (!meta.threads[i])
		{
			printf("error creating threads\n");
			return (EXIT_FAILURE);
		}
		i++;
	}


	free_threads(&meta);
	free_philos(&meta);
	free_forks(&meta);
	return (0);
}
