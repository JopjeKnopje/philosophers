/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 21:34:44 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include "meta.h"
#include "timer.h"

#define FORK_COUNT 7

void	philo_destroy1(t_philo1 *ptr);

void free_2darr(void *arr, size_t block_size, size_t len, void (*func)(void *))
{
	uint32_t i = 0;
	void *p;

	while (i < len)
	{
		p = *(void **) (arr + (i * block_size));
		func(p);
		i++;
	}
	free(arr);
}

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.args.philo_count = FORK_COUNT;
	meta.args.time_to_die = 100;
	forks_init(&meta, meta.args.philo_count);
	philos_init(&meta, meta.args.philo_count);

	// threads init
	threads_init(&meta, philo_main, meta.args.philo_count);
	
	// pass philo to thread

	// pass each thread the "philo_main"

	// check with monitor if philo is dead, if so join the thread?.


	monitor(&meta);


	free_2darr((void *) meta.philos, sizeof(t_philo *), meta.args.philo_count, philo_destroy1);
	free_2darr((void *) meta.forks, sizeof(t_fork *), meta.args.philo_count, philo_destroy1);

	// free_forks(&meta);
	// free_philos(&meta);
	free_threads(&meta);


	return (0);
}
