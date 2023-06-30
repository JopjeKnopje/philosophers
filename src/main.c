/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/06/30 13:12:01 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bits/types/struct_timeval.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <threads.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include "philo.h"

int main(int argc, char *argv[]) 
{

	struct timeval tv1;
	struct timeval tv2;
	struct timezone tz;

	bzero(&tv1, sizeof(struct timeval));
	bzero(&tv2, sizeof(struct timeval));
	bzero(&tz, sizeof(struct timezone));

	signed long delta;

	gettimeofday(&tv1, &tz);

	usleep(100000);
	// sleep(1);

	gettimeofday(&tv2, &tz);
	delta = (tv2.tv_usec) - (tv1.tv_usec);
	printf("delta %ld\n", delta);



	return (0);
}
