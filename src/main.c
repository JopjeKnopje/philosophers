/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/22 23:18:27 by joppe         ########   odam.nl         */
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

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.args.philo_count = FORK_COUNT;
	meta.args.eat_threshold = 100000;
	forks_init(&meta, meta.args.philo_count);
	philos_init(&meta, meta.args.philo_count);

	meta.clock = timer_init();
	timer_start(meta.clock);
	pthread_mutex_init(&meta.print_mutex, NULL);

	threads_init(&meta, philo_main, meta.args.philo_count);


	// check with monitor if philo is dead, if so join the thread?.
	monitor(&meta);


	free_forks(&meta);


	// meuk.c
	// sleep(1);
	free_threads(&meta);
	free_philos(&meta);
	timer_free(meta.clock);
	pthread_mutex_destroy(&meta.print_mutex);


	return (0);
}
