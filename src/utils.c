/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   utils.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/26 18:24:18 by joppe         #+#    #+#                 */
/*   Updated: 2023/07/23 16:19:29 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
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

long get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec) / 1000;
}

void sleep_ms(long ms)
{
	usleep(ms * 1000);
}
