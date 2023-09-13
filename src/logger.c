/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   logger.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: jboeve <jboeve@student.codam.nl>            +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/09/13 16:41:06 by jboeve        #+#    #+#                 */
/*   Updated: 2023/09/13 16:42:21 by jboeve        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "meta.h"



static const char *LOG_TEXT[] = {
	"%ld %d has taken a fork\n",
	"%ld %d is eating\n",
	"%ld %d is sleeping\n",
	"%ld %d is thinking\n",
	"%ld %d died\n",
};


void logger_log(t_logger *logger, t_philo *p, t_status status)
{

}

