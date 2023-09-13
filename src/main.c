/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/13 15:58:41 by jboeve        ########   odam.nl         */
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

#define FORK_COUNT 5

int sim_start(t_meta *meta)
{
	forks_init(meta, meta->args.philo_count);
	if (philos_init(meta, meta->args.philo_count))
	{
		printf("philos_init failed\n");
		return (0);
	}
	return (1);
}

int sim_stop(t_meta *meta)
{
	free_forks(meta);
	free_philos(meta);
	return (1);
}

int parse(t_args *args, int argc, char *argv[])
{
	args->philo_count = FORK_COUNT;
	args->time_to_die = 1000;
	args->time_to_eat = 999;
	return (1);
}

int philosophers(int argc, char *argv[])
{
	t_meta meta;

	// parse and set argv fields
	if (!parse(&meta.args, argc, argv))
		return (EXIT_FAILURE);
	// start sim (which is blocking)
	if (!sim_start(&meta))
		return (EXIT_FAILURE);
	// stop sim
	sim_stop(&meta);
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	return philosophers(argc, argv);
}
