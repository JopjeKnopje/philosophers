/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:32:41 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/28 18:53:55 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdint.h>
#include <stdlib.h>

typedef enum e_status {
	STATUS_FORK,
	STATUS_EAT,
	STATUS_SLEEP,
	STATUS_THINK,
	STATUS_DEAD,
}	t_status; 

typedef struct s_fork {
	pthread_mutex_t mutex;
	uint32_t		id;
}	t_fork;

typedef struct s_philo {
	t_status status;
}	t_philo;

typedef struct s_meta {
	t_philo		**philos;
	t_fork		**forks;
	uint32_t	philo_count;
}	t_meta;



// forks.c
int8_t	forks_init(t_meta *meta, size_t count);
void	fork_destroy(t_fork *f);

// utils.c
void	*ft_calloc(size_t nmemb, size_t size);

// free.c
void free_forks(t_meta *meta);

#endif
