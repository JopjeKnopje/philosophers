/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   monitor.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: joppe <jboeve@student.codam.nl>             +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/07/22 20:44:58 by joppe         #+#    #+#                 */
/*   Updated: 2023/09/11 16:53:38 by joppe         ########   odam.nl         */
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
	return (NULL);
}
