/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   forks.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/26 18:17:25 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/26 20:47:23 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <string.h>

static t_fork	*fork_init()
{
	t_fork	*f;
	f = ft_calloc(sizeof(t_fork), 1);
	if (!f)
		return (NULL);
	f->s = ft_calloc(sizeof(char), 10);
	memset(f->s, 'a', 9);
	return (f);
}

int8_t	forks_init(t_meta *meta, size_t count)
{
	u_int32_t	i;

	i = 0;
	meta->forks = ft_calloc(sizeof(t_fork *), count);
	if (!meta->forks)
		return (1);
	while (i < count)
	{
		meta->forks[i] = fork_init();
		if (!meta->forks[i])
			return (1);
		i++;
	}
	return (0);
}
