/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:32:41 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/26 19:55:54 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>

typedef enum e_status {
	STATUS_FORK,
	STATUS_EAT,
	STATUS_SLEEP,
	STATUS_THINK,
	STATUS_DEAD,
}	t_status; 

typedef struct s_fork {
	// some mutex bs
	char	*s;
}	t_fork;

typedef struct s_philo {
	t_status status;
}	t_philo;

typedef struct s_meta {
	t_philo	**philos;
	t_fork	**forks;
}	t_meta;



// forks.c
int8_t	forks_init(t_meta *meta, size_t count);

// utils.c
void	*ft_calloc(size_t nmemb, size_t size);


#endif
