/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_wait_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/17 20:58:54 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_wait_err(int usecs)
{
	int	error_code;

	error_code = usleep(usecs);
	if (error_code)
		printf(ERROR_WAIT);
}

int	ph_wait_ms(int ms, t_thread_data *data)
{
	struct timeval	start;
	struct timeval	end;
	long long		delta_time;
	long long		delta_utime;

	gettimeofday(&start, NULL);
	delta_time = 0;
	delta_utime = 0;
	while (ph_to_milliseconds(delta_time, delta_utime) < ms)
	{
		ph_wait_err(10);
		gettimeofday(&end, NULL);
		delta_time = (long long)(end.tv_sec - start.tv_sec);
		delta_utime = (long long)(end.tv_usec - start.tv_usec);
		if (delta_utime < 0)
		{
			delta_time --;
			delta_utime += MICROSECONDS_IN_A_SECOND;
		}
		if (!data->simulation->all_alive || data->simulation->all_ate)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
