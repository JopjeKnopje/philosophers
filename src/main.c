/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 00:51:47 by joppe         ########   odam.nl         */
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

#define FORK_COUNT 100

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.args.philo_count = FORK_COUNT;
	meta.args.eat_threshold = 100;
	meta.clock = timer_init();
	forks_init(&meta, meta.args.philo_count);
	philos_init(&meta, meta.args.philo_count);

	pthread_mutex_init(&meta.status_mutex, NULL);
	pthread_mutex_init(&meta.start_mutex, NULL);


	pthread_mutex_lock(&meta.start_mutex);
	threads_init(&meta, philo_main, meta.args.philo_count);
	timer_start(meta.clock);
	pthread_mutex_unlock(&meta.start_mutex);

	monitor(&meta);



	free_forks(&meta);

	free_philos(&meta);
	timer_free(meta.clock);
	pthread_mutex_destroy(&meta.status_mutex);
	pthread_mutex_destroy(&meta.start_mutex);


	return (0);
}
