/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/17 20:50:30 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*ph_philo_actions(void *arg)
{
	t_thread_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	data = (t_thread_data *) arg;
	while (!data->simulation->start)
		usleep(MICROSECONDS_IN_A_MILLISECOND);
	left_fork = &data->simulation->philosophers[data->philosopher].fork;
	right_fork = data->simulation->philosophers[data->philosopher].r_fork;
	if (data->philosopher % 2 == 1)
		usleep(MICROSECONDS_IN_A_MILLISECOND);
	while (data->simulation->all_alive && !data->simulation->all_ate)
	{
		if (ph_eat(data, left_fork, right_fork) == EXIT_FAILURE)
			break ;
		ph_display_status(data, STATUS_IS_SLEEPING);
		if (!data->simulation->all_alive || data->simulation->all_ate)
			break ;
		ph_wait_ms(data->simulation->sleep_time, data);
		if (!data->simulation->all_alive || data->simulation->all_ate)
			break ;
		ph_display_status(data, STATUS_IS_THINKING);
	}
	return ((void *) THREAD_EXIT_SUCCESS);
}
