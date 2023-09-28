/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/28 12:53:03 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		free_forks(meta);
		return (0);
	}

	meta->start_time = get_time_ms();
	pthread_mutex_unlock(&meta->mutex_start);
	// usleep(80 * meta->args.philo_count);
	usleep(1);
	monitor(meta);
	return (1);
}

void sim_set_stop(t_meta *meta)
{
	pthread_mutex_lock(&meta->mutex_running);
	meta->sim_stop = true;
	pthread_mutex_unlock(&meta->mutex_running);
}

bool sim_get_stop(t_meta *meta)
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
	argc--;

	printf("argc: %d\n", argc);
	if (argc >= 4)
		return (0);


	int i = 0;
	uint32_t *ptr = (uint32_t *) args;
	while (i < argc)
	{
		uint32_t num = ft_atoi(argv[i + 1]);
		ptr[i] = num;
		i++;
	}

	// args->philo_count = 3;
	// args->time_to_die = 125;
	// args->time_to_eat = 60;
	// args->time_to_sleep = 60;

	i = 0;
	while (i < argc)
	{
		printf("[%i] -> %u\n", i, ptr[i]);
		i++;
	}
	return (1);
}

int philosophers(int argc, char *argv[])
{
	t_meta meta;

	bzero(&meta, sizeof(t_meta));
	// parse and set argv fields
	if (!parse(&meta.args, argc, argv))
	{
		fprintf(stderr, "Wrong input!\n");
		return (EXIT_FAILURE);
	}
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
