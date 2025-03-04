/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_run_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static	void	ph_handle_error(t_philosopher *philosophers, int i)
{
	pthread_t	thread;
	int			error_code;
	void		*exit_status;

	i --;
	while (0 <= i)
	{
		thread = philosophers[i].thread;
		error_code = pthread_join(thread, &exit_status);
		if (error_code)
		{
			printf(ERROR_JOIN, error_code);
			error_code = RESET_ERROR_CODE;
		}
		if (exit_status)
		{
			printf(ERROR_STATUS_CODE, (intptr_t) exit_status);
			exit_status = RESET_STATUS_CODE;
		}
		i --;
	}
}

static	void	ph_set_start_meal_time(t_simulation *simulation, size_t i)
{
	t_philosopher	*philosopher;

	philosopher = &simulation->philosophers[i];
	philosopher->meal_time = simulation->start_time;
}

static	int	ph_compute_start_time(t_simulation *simulation)
{
	int	is_failure;

	is_failure = gettimeofday(&simulation->start_time, NULL);
	if (is_failure)
	{
		printf(ERROR_TIME);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ph_run_threads(t_thread_data *data)
{
	t_simulation	*simulation;
	pthread_t		*thread;
	size_t			i;
	int				err;

	i = 0;
	simulation = data[i].simulation;
	if (ph_compute_start_time(simulation) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (i < simulation->philo_amount)
	{
		data[i].philosopher = i;
		thread = &simulation->philosophers[i].thread;
		ph_set_start_meal_time(simulation, i);
		err = pthread_create(thread, NULL, ph_philo_actions, (void *) &data[i]);
		if (err)
		{
			printf(ERROR_THREAD, err);
			ph_handle_error(simulation->philosophers, (int) i);
			return (EXIT_FAILURE);
		}
		i ++;
	}
	return (EXIT_SUCCESS);
}
