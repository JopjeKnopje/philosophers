/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/12 16:27:05 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include "meta.h"

#define FORK_COUNT 5

bool sim_start(t_meta *meta, int argc, char *argv[]) 
{
	forks_init(meta, meta->args.philo_count);
	philos_init(meta, meta->args.philo_count);
	threads_init(meta, philo_main, meta->args.philo_count);
	monitor_init(meta);

	return (true);
}

bool sim_stop(t_meta *meta)
{
	free_forks(meta);
	free_philos(meta);
	return (true);
}

bool parse(t_args *args, int argc, char *argv[])
{
	args->philo_count = FORK_COUNT;
	args->time_to_die = 1000;
	args->time_to_eat = 999;
	return (true);
}

int philosophers(int argc, char *argv[])
{
	t_meta meta;

	// parse and set argv fields
	if (!parse(&meta.args, argc, argv))
		return (EXIT_FAILURE);
	// start sim (which is blocking)
	if (!sim_start(&meta, argc, argv))
		return (EXIT_FAILURE);
	sim_stop(&meta);
	// stop sim
	return (0);
}

int main(int argc, char *argv[])
{
	return philosophers(argc, argv);
}
