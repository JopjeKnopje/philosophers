/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:32:41 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/21 13:39:36 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include "timer.h"

typedef enum e_status {
	STATUS_NONE,
	STATUS_FORK,
	STATUS_EAT,
	STATUS_SLEEP,
	STATUS_THINK,
	STATUS_DEAD,
}	t_status; 

static const char *LOG_TEXT[] = {
	"%ld %d NONE\n",
	"%ld %d has taken a fork\n",
	"%ld %d is eating\n",
	"%ld %d is sleeping\n",
	"%ld %d is thinking\n",
	"%ld %d died\n",
};

typedef enum e_philo_fork {
	PHILO_FORK_LEFT,
	PHILO_FORK_RIGHT,
	PHILO_FORK_COUNT,
}	t_philo_fork; 

typedef struct s_fork {
	pthread_mutex_t mutex;
	uint32_t		id;
}	t_fork;

typedef struct s_philo {
	t_fork		*forks[PHILO_FORK_COUNT];
	t_timer 	*timer;
	t_status	status;
	uint32_t	id;
}	t_philo;

typedef struct s_meta {
	t_timer 	*timer_sim;
	t_philo		**philos;
	t_fork		**forks;
	pthread_t	**threads;
	uint32_t	philo_count;
	uint32_t 	time_to_die;
}	t_meta;

// philo.c
int8_t	philos_init(t_meta *meta, uint32_t count);
void	philo_destroy(t_philo *p);
void philo_set_status(t_philo *p, t_timer *sim_timer, t_status s);

// philo_action.c
void	*philo_routine(void *arg);

// philo_probe.c
int8_t philo_is_dead(t_philo *p, t_timer *sim_timer, uint32_t time_to_die);

// forks.c
int8_t	forks_init(t_meta *meta, size_t count);
void	fork_destroy(t_fork *f);

// utils.c
void	*ft_calloc(size_t nmemb, size_t size);
long	get_time(void);

// thread.c
int8_t	threads_init(t_meta *meta, void *(*routine)(void *), uint32_t count);
void	thread_destroy(pthread_t *t);

// monitor.c
void	monitor(t_meta *meta);

// free.c
void	free_forks(t_meta *meta);
void	free_philos(t_meta *meta);
void	free_threads(t_meta *meta);

// meuk.c
void	print_philos(t_philo *ps[], uint32_t count);
void	print_philo(t_philo *p);

#endif
