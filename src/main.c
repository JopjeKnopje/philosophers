/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/08/29 18:55:55 by joppe         ########   odam.nl         */
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


int philosophers(int argc, char *argv[]) 
{
	t_meta meta;

	meta.args.philo_count = FORK_COUNT;
	meta.args.time_to_die = 1000;
	meta.args.time_to_eat = 999;


	forks_init(&meta, meta.args.philo_count);
	philos_init(&meta, meta.args.philo_count);

	threads_init(&meta, philo_main, meta.args.philo_count);

	monitor(&meta);


	free_forks(&meta);
	free_philos(&meta);

	return (0);
}
int main(int argc, char *argv[])
{
	return (philosophers(argc, argv));
}
