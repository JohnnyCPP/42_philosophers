/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_update_meal_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/17 21:19:04 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_update_meal_time(t_thread_data *data)
{
	int				is_failure;
	t_philosopher	*philosopher;

	philosopher = &data->simulation->philosophers[data->philosopher];
	is_failure = pthread_mutex_lock(&data->simulation->reading_eat_time);
	if (is_failure)
	{
		printf(ERROR_LOCK_MUTEX, is_failure);
		is_failure = 0;
	}
	is_failure = gettimeofday(&philosopher->meal_time, NULL);
	if (is_failure)
	{
		printf(ERROR_MEAL_TIME);
		is_failure = 0;
	}
	is_failure = pthread_mutex_unlock(&data->simulation->reading_eat_time);
	if (is_failure)
		printf(ERROR_UNLOCK_MUTEX, is_failure);
}
