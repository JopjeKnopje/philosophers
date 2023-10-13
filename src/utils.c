/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   utils.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/26 18:24:18 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/13 13:53:09 by joppe         ########   odam.nl         */
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

long	ft_atol(const char *s)
{
	int		i;
	int		sign;
	long	num;

	num = 0;
	sign = 0;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while ((s[i] == '-' || s[i] == '+') && !sign)
	{
		if (s[i] == '-')
			sign = -1;
		if (s[i] == '+')
			sign = 1;
		i++;
	}
	if (!sign)
		sign = 1;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + s[i] - '0';
		i++;
	}
	return (num * sign);
}

unsigned long get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	// return ((tv.tv_sec * 1000000) + tv.tv_usec) / 1000;
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

