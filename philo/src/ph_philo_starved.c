/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_starved.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/17 21:18:16 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static	long long	ph_diff(struct timeval *end, struct timeval *start)
{
	long long	delta_time;
	long long	delta_utime;

	delta_time = (long long)(end->tv_sec - start->tv_sec);
	delta_utime = (long long)(end->tv_usec - start->tv_usec);
	if (delta_utime < 0)
	{
		delta_time --;
		delta_utime += MICROSECONDS_IN_A_SECOND;
	}
	return (ph_to_milliseconds(delta_time, delta_utime));
}

int	ph_philo_starved(t_simulation *sim, size_t i)
{
	long long	last_meal;
	int			is_failure;
	int			starved;

	is_failure = gettimeofday(&sim->current_time, NULL);
	if (is_failure)
	{
		printf(ERROR_CURRENT_TIME);
		is_failure = 0;
	}
	is_failure = pthread_mutex_lock(&sim->reading_eat_time);
	if (is_failure)
	{
		printf(ERROR_LOCK_MUTEX, is_failure);
		is_failure = 0;
	}
	last_meal = ph_diff(&sim->current_time, &sim->philosophers[i].meal_time);
	is_failure = pthread_mutex_unlock(&sim->reading_eat_time);
	if (is_failure)
		printf(ERROR_UNLOCK_MUTEX, is_failure);
	starved = last_meal > (long long) sim->die_time;
	return (starved);
}
