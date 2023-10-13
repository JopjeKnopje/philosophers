/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/13 19:34:35 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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

void print_args(t_args *args, size_t count)
{
	size_t i = 0;
	int32_t *p_args = (int32_t *) args;

	printf("---------------------\n");
	while (i < count)
	{
		printf("args[%ld] -> [%d]\n", i, p_args[i]);
		i++;
	}

}

t_parse_error parse(t_args *args, int argc, char *argv[])
{
	long tmp;
	int32_t i;
	int32_t *p_args;

	if (argc < 5 || argc > 6)
		return (PE_ARGS);

	print_args(args, 5);

	memset(args, -1, sizeof(t_args));
	print_args(args, 5);

	i = 0;
	p_args = (int32_t *) args;
	while (i < argc - 1)
	{
		tmp = ft_atol(argv[i + 1]);
		if (tmp < 0 || tmp > INT_MAX)
			return (PE_OVERFLOW);
		p_args[i] = tmp;
		i++;
	}



	print_args(args, argc - 1);
	return (PE_SUCCESS);
}

int philosophers(int argc, char *argv[])
{
	t_parse_error	err;
	t_meta			meta;

	bzero(&meta, sizeof(t_meta));

	err = parse(&meta.args, argc, argv);
	if (err)
	{
		write(STDERR_FILENO, PE_MESSAGES[err], ft_strlen(PE_MESSAGES[err]));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);

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
