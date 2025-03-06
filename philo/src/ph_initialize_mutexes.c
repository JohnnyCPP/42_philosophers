/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_initialize_mutexes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 19:05:14 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static	int	ph_initialize_print_mutex(t_simulation *simulation)
{
	int	error_code;

	error_code = pthread_mutex_init(&simulation->attempt_to_print, NULL);
	if (error_code)
	{
		printf(ERROR_MUTEX, error_code);
		ph_destroy_philo_mutexes(simulation);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

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
		err = pthread_mutex_destroy(&philosophers[i].eating);
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
	int				error_code_2;

	philosophers = simulation->philosophers;
	i = 0;
	while (i < simulation->philo_amount)
	{
		error_code = pthread_mutex_init(&philosophers[i].fork, NULL);
		if (error_code)
			return (ph_handle_mu_err(philosophers, (int)(i - 1), error_code));
		error_code = pthread_mutex_init(&philosophers[i].eating, NULL);
		if (error_code)
		{
			error_code_2 = pthread_mutex_destroy(&philosophers[i].fork);
			if (error_code_2)
				printf(ERROR_MUTEX_DESTROY, error_code_2);
			return (ph_handle_mu_err(philosophers, (int) i, error_code));
		}
		i ++;
	}
	if (ph_initialize_print_mutex(simulation) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
