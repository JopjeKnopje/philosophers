/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   parse.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/10/13 22:49:12 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/19 18:32:53 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <limits.h>
#include <stdio.h>

static int	is_number(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_parse_error	parse(t_args *args, int argc, char *argv[])
{
	long	tmp;
	int32_t	i;
	int32_t	*p_args;

	if (argc < 5 || argc > 6)
		return (PE_ARGS);
	ft_memset(args, ARG_NOT_SET, sizeof(t_args));
	i = 0;
	p_args = (int32_t *) args;
	while (i < argc - 1)
	{
		if (!is_number(argv[i + 1]))
			return (PE_ARGS);
		tmp = ft_atol(argv[i + 1]);
		if (tmp < 0 || tmp > INT_MAX)
			return (PE_OVERFLOW);
		p_args[i] = tmp;
		i++;
	}
	// TODO Check if time-to-sleep > time-to-die or time-to-eat > time-to-die.
	return (PE_SUCCESS);
}


