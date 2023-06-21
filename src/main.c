/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/21 16:56:51 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "philo.h"


void *routine(void *p)
{
	int i = 0;
	while (i < 10)
	{
		printf("i: %d\n", i);
		i++;
	}
	return p;
}

pthread_t *thread1;

int main(int argc, char *argv[]) 
{
	t_meta meta;
	thread1 = malloc(sizeof(pthread_t));

	pthread_create(thread1, NULL, &routine, &meta);

	pthread_join(*thread1, NULL);
	return (0);
}
