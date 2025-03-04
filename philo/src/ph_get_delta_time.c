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

static long long	ph_to_milliseconds(long long s, long long microseconds)
{
	long long	s_to_ms;
	long long	microseconds_to_ms;

	s_to_ms = s * MILLISECONDS_IN_A_SECOND;
	microseconds_to_ms = microseconds / MICROSECONDS_IN_A_MILLISECOND;
	return (s_to_ms + microseconds_to_ms);
}

long long	ph_get_delta_time(t_simulation *simulation)
{
	struct timeval	start;
	struct timeval	final;
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
	final = simulation->current_time;
	delta_time = (long long)(final.tv_sec - start.tv_sec);
	delta_utime = (long long)(final.tv_usec - start.tv_usec);
	if (delta_utime < 0)
	{
		delta_time --;
		delta_utime += MICROSECONDS_IN_A_SECOND;
	}
	return (ph_to_milliseconds(delta_time, delta_utime));
}
