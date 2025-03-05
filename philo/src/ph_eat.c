/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_wait_for_my_fate(t_thread_data *data)
{
	ph_display_status(data, STATUS_TOOK_FORK);
	ph_wait_ms(data->simulation->die_time);
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

int	ph_g_f_2(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r, int err)
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
	err = pthread_mutex_unlock(&d->simulation->attempt_to_forks);
	if (err)
		printf(ERROR_RELEASE_FORKS);
	return (EXIT_SUCCESS);
}

int	ph_get_forks(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r)
{
	int	error_code;

	if (d->simulation->philo_amount == 1)
		return (ph_wait_for_my_fate(d));
	error_code = pthread_mutex_lock(&d->simulation->attempt_to_forks);
	if (error_code)
	{
		printf(ERROR_GET_FORKS);
		error_code = 0;
	}
	if (ph_simulation_ended(d, error_code) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ph_g_f_2(d, l, r, error_code);
	return (EXIT_SUCCESS);
}

int	ph_eat(t_thread_data *data, pthread_mutex_t *l, pthread_mutex_t *r)
{
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
	ph_wait_ms(data->simulation->eat_time);
	ph_release_f(l, r);
	return (EXIT_SUCCESS);
}
