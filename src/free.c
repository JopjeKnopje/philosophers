/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   free.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/28 18:52:05 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/21 16:14:02 by jboeve        ########   odam.nl         */
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

