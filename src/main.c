/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/07 00:50:10 by joppe         ########   odam.nl         */
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
#include "timer.h"

int main(int argc, char *argv[]) 
{
	t_timer *timer = timer_init();

	timer_start(timer);

	// sleep(1);
	usleep(100000);

	t_timeval *delta = timer_delta(timer);
	printf("d s %ld | d us %ld\n", delta->tv_sec, delta->tv_usec);
	timer_free(timer);



	return (0);
}
