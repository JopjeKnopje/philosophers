/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   philo_eat.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/10/20 00:25:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/20 00:27:29 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"

int32_t	philo_get_eat_count(t_philo *p)
{
	int32_t	count;

	pthread_mutex_lock(&p->mutex_eat_count);
	count = p->eat_count;
	pthread_mutex_unlock(&p->mutex_eat_count);
	return (count);
}

void	philo_update_eat_time(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_eat);
	p->last_eat_time = get_time_ms();
	pthread_mutex_unlock(&p->mutex_eat);
}

void	philo_update_eat_count(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_eat_count);
	p->eat_count++;
	pthread_mutex_unlock(&p->mutex_eat_count);
}
