/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/29 16:44:02 by joppe         ########   odam.nl         */
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
	// print_philo(philo);
	printf("test123\n");

	
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
	while (i < meta.philo_count)
	{
		thread_init(&meta, &routine, &meta.philos[i]);
		i++;
	}


	free_threads(&meta);
	free_philos(&meta);
	free_forks(&meta);
	return (0);
}
