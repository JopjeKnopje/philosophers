/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/06/21 16:29:24 by joppe         #+#    #+#                 */
/*   Updated: 2023/10/19 17:57:01 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <unistd.h>

const static char *PE_MESSAGES[] = {
	NULL,
 	"usage: philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n",
	"Integer overflow!\n",
};

int philosophers(int argc, char *argv[])
{
	t_parse_error	err;
	t_meta			meta;

	ft_memset(&meta, 0, sizeof(t_meta));
	err = parse(&meta.args, argc, argv);
	if (err)
	{
		write(STDERR_FILENO, PE_MESSAGES[err], ft_strlen(PE_MESSAGES[err]));
		return (EXIT_FAILURE);
	}
	if (!sim_start(&meta))
		return (EXIT_FAILURE);
	sim_cleanup(&meta);
	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	return philosophers(argc, argv);
}

