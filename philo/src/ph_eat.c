/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 17:22:40 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_wait_for_my_fate(t_thread_data *data)
{
	int	error_code;
	int	ms;

	ph_display_status(data, STATUS_TOOK_FORK);
	ms = data->simulation->die_time;
	while (ms > 0)
	{
		error_code = usleep(MICROSECONDS_IN_A_MILLISECOND);
		if (error_code)
		{
			printf(ERROR_WAIT);
			error_code = RESET_ERROR_CODE;
		}
		ms --;
	}
	return (EXIT_FAILURE);
}

int	ph_simulation_ended(t_thread_data *d, int error_code)
{
	if (!d->simulation->all_alive || d->simulation->all_ate)
	{
		error_code = pthread_mutex_unlock(&d->simulation->attempt_to_forks);
		if (error_code)
			printf(ERROR_RELEASE_FORKS);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ph_get_forks(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r)
{
	int	error_code;

	if (d->simulation->philo_amount == 1)
		return (ph_wait_for_my_fate(d));
	error_code = 0;
	if (ph_simulation_ended(d, error_code) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (d->philosopher % 2 == 1)
		ph_g_f_l(d, l, r, error_code);
	else
		ph_g_f_r(d, l, r, error_code);
	return (EXIT_SUCCESS);
}

int	ph_eat(t_thread_data *data, pthread_mutex_t *l, pthread_mutex_t *r)
{
	if (data->philosopher % 2 == 1)
		usleep(MICROSECONDS_IN_A_MILLISECOND * 5);
	if (ph_get_forks(data, l, r) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ph_update_meal_time(&data->simulation->philosophers[data->philosopher]);
	data->simulation->philosophers[data->philosopher].meals_amount ++;
	if (!data->simulation->all_alive || data->simulation->all_ate)
	{
		ph_release_f(l, r);
		return (EXIT_FAILURE);
	}
	ph_display_status(data, STATUS_IS_EATING);
	ph_wait_ms(data->simulation->eat_time, data);
	ph_release_f(l, r);
	return (EXIT_SUCCESS);
}
