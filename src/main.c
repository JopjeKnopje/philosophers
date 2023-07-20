/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/20 15:33:57 by jboeve        ########   odam.nl         */
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
#include "philo.h"
#include "timer.h"

#define FORK_COUNT 5

void *routine(void *arg)
{
	t_philo *philo = arg;

	print_philo(philo);

	
	
	return (NULL);
}

void monitor(t_meta *meta)
{
	uint32_t	i;

	timer_start(meta->timer_sim);

	i = 0;
	while (i < meta->philo_count) 
	{
		if (philo_is_dead(meta->timer_sim, meta->philos[i]))
		{
		
		}
		i++;
	}
	// is philo dead

}

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.philo_count = FORK_COUNT;
	forks_init(&meta, meta.philo_count);
	philos_init(&meta, meta.philo_count);
	threads_init(&meta, routine, meta.philo_count);

	meta.timer_sim = timer_init();


	monitor(&meta);


	free_threads(&meta);
	free_philos(&meta);
	free_forks(&meta);
	return (0);
}
