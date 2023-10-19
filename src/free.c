/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   free.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/28 18:52:05 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/19 16:17:28 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"

void free_forks(t_meta *meta)
{
	uint32_t i = 0;
	
	while (i < meta->args.philo_count)
	{
		fork_destroy(&meta->forks[i]);
		i++;
	}
	free(meta->forks);
}

void free_philos(t_meta *meta)
{
	int32_t i = 0;

	while (i < meta->args.philo_count)
	{
		philo_join(&meta->philos[i]);
		i++;
	}
	free(meta->philos);
}
