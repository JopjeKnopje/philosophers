/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 00:09:21 by joppe         ########   odam.nl         */
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

#define FORK_COUNT 5

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.args.philo_count = FORK_COUNT;
	meta.args.eat_threshold = 100;
	forks_init(&meta, meta.args.philo_count);
	philos_init(&meta, meta.args.philo_count);

	meta.clock = timer_init();

	pthread_mutex_init(&meta.print_mutex, NULL);
	pthread_mutex_init(&meta.start_mutex, NULL);

	pthread_mutex_lock(&meta.start_mutex);


	timer_start(meta.clock);
	threads_init(&meta, philo_main, meta.args.philo_count);

	pthread_mutex_unlock(&meta.start_mutex);

	// check with monitor if philo is dead, if so join the thread?.
	monitor(&meta);




	free_forks(&meta);

	// meuk.c
	usleep(100000);


	free_philos(&meta);
	timer_free(meta.clock);
	pthread_mutex_destroy(&meta.print_mutex);
	pthread_mutex_destroy(&meta.start_mutex);


	return (0);
}
