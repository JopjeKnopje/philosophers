/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/30 12:47:47 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bits/types/struct_timeval.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include "philo.h"

#define FORK_COUNT 5

void *routine(void *arg)
{
	t_philo *philo = arg;

	print_philo(philo);

	int i = 0;
	while (i < 10)
	{
		printf("i: %d\n", i);
		i++;
	}
	printf("done\n");
	
	return (NULL);
}

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.philo_count = FORK_COUNT;
	forks_init(&meta, meta.philo_count);
	philos_init(&meta, meta.philo_count);


	int i = 0;
	meta.threads = ft_calloc(sizeof(pthread_t *), meta.philo_count);
	while (i < meta.philo_count)
	{
		meta.threads[i] = thread_init(&meta, &routine, meta.philos[i]);
		if (!meta.threads[i])
		{
			printf("error creating threads\n");
			return (EXIT_FAILURE);
		}
		usleep(1 * 1000000 / 2);
		i++;
	}

	struct timeval tv;
	struct timezone tz;
	tz.tz_dsttime = 0;
	tz.tz_minuteswest = 0;
	long delta = 0;

	gettimeofday(&tv, &tz);

	delta = tv.tv_usec;
	printf("useconds %ld\n", tv.tv_usec);
	// usleep(1 * 1000000);
	sleep(3);

	gettimeofday(&tv, &tz);

	delta = tv.tv_usec - delta;
	printf("useconds %ld\n", tv.tv_usec);
	printf("delta %ld\n", delta);


	free_threads(&meta);
	free_philos(&meta);
	free_forks(&meta);
	return (0);
}
