/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_get_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 17:02:58 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_g_f_r(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r, int err)
{
	err = pthread_mutex_lock(r);
	if (err)
	{
		printf(ERROR_RIGHT_FORK);
		err = 0;
	}
	ph_display_status(d, STATUS_TOOK_FORK);
	err = pthread_mutex_lock(l);
	if (err)
	{
		printf(ERROR_LEFT_FORK);
		err = 0;
	}
	ph_display_status(d, STATUS_TOOK_FORK);
	return (EXIT_SUCCESS);
}

int	ph_g_f_l(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r, int err)
{
	err = pthread_mutex_lock(l);
	if (err)
	{
		printf(ERROR_LEFT_FORK);
		err = 0;
	}
	ph_display_status(d, STATUS_TOOK_FORK);
	err = pthread_mutex_lock(r);
	if (err)
	{
		printf(ERROR_RIGHT_FORK);
		err = 0;
	}
	ph_display_status(d, STATUS_TOOK_FORK);
	return (EXIT_SUCCESS);
}
