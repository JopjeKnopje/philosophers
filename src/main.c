/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/17 20:37:28 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include "meta.h"

int sim_start(t_meta *meta)
{
	if (pthread_mutex_init(&meta->mutex_start, NULL))
	{
		printf("mutex_init failed\n");
		return (0);
	}
	pthread_mutex_lock(&meta->mutex_start);

	if (pthread_mutex_init(&meta->mutex_log, NULL))
	{
		printf("mutex_log failed\n");
		return (0);
	}
	if (pthread_mutex_init(&meta->mutex_running, NULL))
	{
		printf("mutex_log failed\n");
		return (0);
	}
	if (forks_init(meta, meta->args.philo_count))
	{
		printf("forks_init failed\n");
		return (0);
	}
	if (philos_init(meta, meta->args.philo_count))
	{
		printf("philos_init failed\n");
		return (0);
	}

	meta->start_time = get_time_ms();
	pthread_mutex_unlock(&meta->mutex_start);
	sleep_ms(1);
	monitor(meta);
	return (1);
}

void sim_stop(t_meta *meta)
{
	pthread_mutex_lock(&meta->mutex_running);
	meta->sim_stop = true;
	pthread_mutex_unlock(&meta->mutex_running);
}

bool sim_should_stop(t_meta *meta)
{
	bool	running;

	pthread_mutex_lock(&meta->mutex_running);
	running = meta->sim_stop;
	pthread_mutex_unlock(&meta->mutex_running);
	return (running);
}

int sim_cleanup(t_meta *meta)
{
	free_philos(meta);
	free_forks(meta);
	return (1);
}

int parse(t_args *args, int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	args->philo_count = 5;
	args->time_to_die = 2000;
	args->time_to_eat = 1000;
	args->time_to_sleep = 1000;
	return (1);
}

int philosophers(int argc, char *argv[])
{
	t_meta meta;

	bzero(&meta, sizeof(t_meta));
	// parse and set argv fields
	if (!parse(&meta.args, argc, argv))
		return (EXIT_FAILURE);
	// start sim (which is blocking)
	if (!sim_start(&meta))
		return (EXIT_FAILURE);
	// stop sim
	sim_cleanup(&meta);
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	return philosophers(argc, argv);
}
