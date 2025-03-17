/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy_mutexes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/17 21:07:31 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_destroy_mutexes(t_simulation *simulation)
{
	t_philosopher	*philosophers;
	size_t			i;
	int				error_code;

	philosophers = simulation->philosophers;
	i = 0;
	error_code = pthread_mutex_destroy(&simulation->reading_eat_time);
	if (error_code)
	{
		printf(ERROR_MUTEX_DESTROY, error_code);
		error_code = RESET_ERROR_CODE;
	}
	while (i < simulation->philo_amount)
	{
		error_code = pthread_mutex_destroy(&philosophers[i].fork);
		if (error_code)
		{
			printf(ERROR_MUTEX_DESTROY, error_code);
			error_code = RESET_ERROR_CODE;
		}
		i ++;
	}
}
