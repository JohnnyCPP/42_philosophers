/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_get_delta_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long long	ph_get_delta_time(t_simulation *simulation)
{
	struct timeval	start;
	struct timeval	end;
	long long		delta_time;
	long long		delta_utime;
	int				is_failure;

	is_failure = gettimeofday(&simulation->current_time, NULL);
	if (is_failure)
	{
		printf(ERROR_CURRENT_TIME);
		return (DELTA_TIME_FAILURE);
	}
	start = simulation->start_time;
	end = simulation->current_time;
	delta_time = (long long)(end.tv_sec - start.tv_sec);
	delta_utime = (long long)(end.tv_usec - start.tv_usec);
	if (delta_utime < 0)
	{
		delta_time --;
		delta_utime += MICROSECONDS_IN_A_SECOND;
	}
	return (ph_to_milliseconds(delta_time, delta_utime));
}
