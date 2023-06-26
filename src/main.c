/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/26 19:55:45 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

#define FORK_COUNT 5

int main(int argc, char *argv[]) 
{
	t_meta meta;

	forks_init(&meta, FORK_COUNT);

	// int i = 0;
	// while (i < FORK_COUNT)
	// {
	// 	printf("i: %d | s[%s]\n", i, meta.forks[i]->s);
	// 	free(meta.forks[i]->s);
	// 	free(meta.forks[i]);
	// 	i++;
	// }
	return (0);
}
