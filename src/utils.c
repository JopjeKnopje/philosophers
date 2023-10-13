/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   utils.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/26 18:24:18 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/13 19:43:38 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

unsigned long get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void sleep_ms(unsigned long ms)
{
	unsigned long old = get_time_ms();
	while (get_time_ms() - old < ms)
	{
		usleep(1000);
	}
}
