/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   meta.h                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:32:41 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/13 14:16:16 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_meta t_meta;

typedef enum e_parse_error {
	PE_SUCCESS,
	PE_ARGS,
	PE_OVERFLOW,
} t_parse_error;

const static char *PE_MESSAGES[] = {
	NULL,
 	"usage: philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n",
	"Integer overflow!\n",
};

typedef enum e_message {
	MESSAGE_FORK,
	MESSAGE_EAT,
	MESSAGE_SLEEP,
	MESSAGE_THINK,
	MESSAGE_DEAD,
}	t_message; 


typedef enum e_philo_fork {
	PHILO_FORK_LEFT,
	PHILO_FORK_RIGHT,
	PHILO_FORK_COUNT,
}	t_philo_fork; 

typedef struct s_fork {
	pthread_mutex_t mutex;
	uint32_t		id;
}	t_fork;

typedef struct s_args {
	int32_t	philo_count;
	int32_t	time_to_die;
	int32_t	time_to_eat;
	int32_t	time_to_sleep;
	int32_t	max_eat_count;
} t_args;

typedef struct s_philo {
	uint32_t		id;
	t_meta 			*meta;
	pthread_mutex_t mutex_meal;
	pthread_t 		thread;
	t_fork			*forks[PHILO_FORK_COUNT];
	unsigned long 	last_eat_time;
	unsigned long 	eat_count;
}	t_philo;


typedef struct s_meta {
	t_philo			*philos;
	t_fork			*forks;
	bool			sim_stop;
	unsigned long 	start_time;
	pthread_mutex_t mutex_log;
	pthread_mutex_t mutex_start;
	pthread_mutex_t mutex_running;
	t_args 			args;
}	t_meta;

// main.c
void			sim_set_stop(t_meta *meta);
bool			sim_get_stop(t_meta *meta);

// forks.c
int8_t			forks_init(t_meta *meta, size_t count);
void			fork_destroy(t_fork *f);

// utils.c
void			*ft_calloc(size_t nmemb, size_t size);
long			ft_atol(const char *s);
unsigned long	get_time_ms(void);
void			sleep_ms(unsigned long ms);

// philo.c
int				philos_init(t_meta *meta, uint32_t count);
void			philo_join(t_philo *p);

// philo_action.c
void		*philo_main(void *arg);

// threads.c
pthread_t	*thread_init(void *(*routine)(void *), void *arg);
int8_t		threads_init(t_meta *meta, void *(*routine)(void *), uint32_t count);
void		thread_destroy(pthread_t *t);

// monitor.c
void	*monitor(t_meta *meta);

// free.c
void		free_forks(t_meta *meta);

// logger.c
void		logger_log(t_philo *p, t_message status);

// meuk.c
void		print_philos(t_philo *ps[], uint32_t count);
void		print_philo(t_philo *p);
void		free_philos(t_meta *meta);
void		free_threads(t_meta *meta);

#endif
