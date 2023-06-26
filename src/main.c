/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/26 16:26:52 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

int i = 0;

pthread_t thread1;
pthread_t thread2;
pthread_mutex_t mutex;


void *routine(void *p)
{
	while (1)
	{
		if (i > 50)
			break;
		pthread_mutex_lock(&mutex);
		printf("i: %d\n", i);
		i++;
		pthread_mutex_unlock(&mutex);
	}
	char *s = ((t_meta *) p)->s;
	return s;
}

int main(int argc, char *argv[]) 
{
	t_meta meta;

	meta.s = "test123";
	pthread_create(&thread1, NULL, &routine, &meta);
	pthread_create(&thread2, NULL, &routine, &meta);

	pthread_mutex_init(&mutex, NULL);

	char *ptr;
	printf("waiting on pthread_join\n");
	pthread_join(thread1, (void **) &ptr);
	pthread_join(thread2, NULL);
	printf("joined the threads\n");
	printf("data from thread1 [%s]\n", ptr);
	return (0);
}
