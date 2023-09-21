/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   utils.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/26 18:24:18 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/21 15:14:27 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	buf_size;
	void	*buffer;

	buf_size = nmemb * size;
	buffer = malloc(buf_size);
	if (buffer)
		memset(buffer, 0, buf_size);
	else
		return (NULL);
	return (buffer);
}

unsigned long get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec) / 1000;
}

void sleep_ms(unsigned long ms)
{
	unsigned long old = get_time_ms();
	while (get_time_ms() - old < ms)
	{
		usleep(ms / (2 * 1000));
	}
}
