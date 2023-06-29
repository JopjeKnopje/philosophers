/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:32:41 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/29 17:24:23 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum e_status {
	STATUS_NONE,
	STATUS_FORK,
	STATUS_EAT,
	STATUS_SLEEP,
	STATUS_THINK,
	STATUS_DEAD,
}	t_status; 

typedef enum e_forks {
	FORK_LEFT,
	FORK_RIGHT,
	FORK_COUNT,
}	t_forks; 

typedef struct s_fork {
	pthread_mutex_t mutex;
	uint32_t		id;
}	t_fork;

typedef struct s_philo {
	t_fork		*forks[FORK_COUNT];
	t_status	status;
	uint32_t	id;
}	t_philo;

typedef struct s_meta {
	t_philo		**philos;
	bool 		start;
	t_fork		**forks;
	pthread_t	**threads;
	uint32_t	philo_count;
}	t_meta;

// philo.c
int8_t	philos_init(t_meta *meta, uint32_t count);
void	philo_destroy(t_philo *p);

// forks.c
int8_t	forks_init(t_meta *meta, size_t count);
void	fork_destroy(t_fork *f);

// utils.c
void	*ft_calloc(size_t nmemb, size_t size);

// thread.c
pthread_t	*thread_init(t_meta *meta, void *(*routine)(void *), void *arg);
void		thread_destroy(pthread_t *t);

// free.c
void free_forks(t_meta *meta);
void free_philos(t_meta *meta);
void free_threads(t_meta *meta);

// meuk.c
void print_philos(t_philo *ps[], uint32_t count);
void print_philo(t_philo *p);

#endif
