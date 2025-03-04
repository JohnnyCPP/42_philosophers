/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_display_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	ph_unlock_display(t_thread_data *data)
{
	int			error_code;

	error_code = pthread_mutex_unlock(&data->simulation->attempt_to_print);
	if (error_code)
		printf(ERROR_UNLOCK_DISPLAY);
}

static void	ph_lock_display(t_thread_data *data)
{
	int			error_code;

	error_code = pthread_mutex_lock(&data->simulation->attempt_to_print);
	if (error_code)
		printf(ERROR_LOCK_DISPLAY);
}

void	ph_display_status(t_thread_data *data, const char *format)
{
	long long	delta_time;

	ph_lock_display(data);
	delta_time = ph_get_delta_time(data->simulation);
	if (delta_time == DELTA_TIME_FAILURE)
		return ;
	printf(format, delta_time, data->philosopher);
	ph_unlock_display(data);
}
