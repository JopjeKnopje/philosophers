/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/12 15:55:31 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"
#include <stdint.h>
#include <stdio.h>

bool monitor_init(t_meta *meta)
{
	meta->monitor_thread = thread_init(monitor, NULL);
	if (!meta->monitor_thread)
		return (false);
	return (true);
}

void *monitor(void *param)
{
	t_meta meta = meta;

	while (true) {
	}
	return (NULL);
}
