/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_initialize_mutexes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/17 21:06:53 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static	int	ph_handle_mu_err(t_philosopher *philosophers, int i, int err)
{
	printf(ERROR_MUTEX, err);
	while (i >= 0)
	{
		err = pthread_mutex_destroy(&philosophers[i].fork);
		if (err)
		{
			printf(ERROR_MUTEX_DESTROY, err);
			err = RESET_ERROR_CODE;
		}
		i --;
	}
	return (EXIT_FAILURE);
}

int	ph_initialize_mutexes(t_simulation *simulation)
{
	t_philosopher	*philosophers;
	size_t			i;
	int				error_code;
	size_t			next;

	philosophers = simulation->philosophers;
	i = 0;
	error_code = pthread_mutex_init(&simulation->reading_eat_time, NULL);
	if (error_code)
		return (EXIT_FAILURE);
	while (i < simulation->philo_amount)
	{
		error_code = pthread_mutex_init(&philosophers[i].fork, NULL);
		if (error_code)
			return (ph_handle_mu_err(philosophers, (int)(i - 1), error_code));
		next = (i + (size_t) NEXT) % simulation->philo_amount;
		philosophers[i].r_fork = &philosophers[next].fork;
		i ++;
	}
	return (EXIT_SUCCESS);
}
