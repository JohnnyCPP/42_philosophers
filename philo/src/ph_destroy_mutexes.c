/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_destroy_mutexes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_destroy_philo_mutexes(t_simulation *simulation)
{
	t_philosopher	*philosophers;
	size_t			i;
	int				error_code;

	philosophers = simulation->philosophers;
	i = 0;
	while (i < simulation->philo_amount)
	{
		error_code = pthread_mutex_destroy(&philosophers[i].fork);
		if (error_code)
			printf(ERROR_MUTEX_DESTROY, error_code);
		i ++;
	}
}

void	ph_destroy_mutexes(t_simulation *simulation)
{
	int	error_code;

	ph_destroy_philo_mutexes(simulation);
	error_code = pthread_mutex_destroy(&simulation->attempt_to_forks);
	if (error_code)
		printf(ERROR_MUTEX_DESTROY, error_code);
	error_code = pthread_mutex_destroy(&simulation->attempt_to_print);
	if (error_code)
		printf(ERROR_MUTEX_DESTROY, error_code);
}
