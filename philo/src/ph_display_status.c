/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_display_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/11 19:49:32 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_display_status(t_thread_data *data, const char *format)
{
	long long	delta_time;

	delta_time = ph_get_delta_time(data->simulation);
	if (delta_time == DELTA_TIME_FAILURE)
		return ;
	if (data->simulation->all_alive && !data->simulation->all_ate)
		printf(format, delta_time, data->philosopher + 1);
}
