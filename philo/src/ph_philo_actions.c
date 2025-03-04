/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_release_f(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r)
{
	int	error_code;

	error_code = pthread_mutex_unlock(l);
	if (error_code)
	{
		printf(ERROR_RELEASE_LEFT);
		error_code = 0;
	}
	error_code = pthread_mutex_unlock(r);
	if (error_code)
	{
		printf(ERROR_RELEASE_RIGHT);
		error_code = 0;
	}
	error_code = pthread_mutex_unlock(&d->simulation->attempt_to_forks);
	if (error_code)
		printf(ERROR_RELEASE_FORKS);
}

void	ph_get_forks(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r)
{
	int	error_code;

	error_code = pthread_mutex_lock(&d->simulation->attempt_to_forks);
	if (error_code)
	{
		printf(ERROR_GET_FORKS);
		error_code = 0;
	}
	error_code = pthread_mutex_lock(l);
	if (error_code)
	{
		printf(ERROR_LEFT_FORK);
		error_code = 0;
	}
	ph_display_status(d, STATUS_TOOK_FORK);
	error_code = pthread_mutex_lock(r);
	if (error_code)
		printf(ERROR_RIGHT_FORK);
	ph_display_status(d, STATUS_TOOK_FORK);
}

void	*ph_philo_actions(void *arg)
{
	t_thread_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	size_t			next;

	data = (t_thread_data *) arg;
	left_fork = &data->simulation->philosophers[data->philosopher].fork;
	next = (data->philosopher + (size_t) NEXT) % data->simulation->philo_amount;
	right_fork = &data->simulation->philosophers[next].fork;
	while (TRUE)
	{
		ph_get_forks(data, left_fork, right_fork);
		ph_update_meal_time(&data->simulation->philosophers[data->philosopher]);
		ph_display_status(data, STATUS_IS_EATING);
		ph_wait_ms(data->simulation->eat_time);
		ph_release_f(data, left_fork, right_fork);
		ph_display_status(data, STATUS_IS_SLEEPING);
		ph_wait_ms(data->simulation->sleep_time);
		ph_display_status(data, STATUS_IS_THINKING);
	}
	return ((void *) THREAD_EXIT_SUCCESS);
}
