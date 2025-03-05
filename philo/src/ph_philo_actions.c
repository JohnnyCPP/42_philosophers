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
	while (data->simulation->all_alive && !data->simulation->all_ate)
	{
		if (ph_eat(data, left_fork, right_fork) == EXIT_FAILURE)
			break ;
		ph_display_status(data, STATUS_IS_SLEEPING);
		if (!data->simulation->all_alive || data->simulation->all_ate)
			break ;
		ph_wait_ms(data->simulation->sleep_time);
		if (!data->simulation->all_alive || data->simulation->all_ate)
			break ;
		ph_display_status(data, STATUS_IS_THINKING);
	}
	return ((void *) THREAD_EXIT_SUCCESS);
}
