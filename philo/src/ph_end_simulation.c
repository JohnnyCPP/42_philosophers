/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_end_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static	void	ph_join_threads(t_thread_data *data)
{
	t_simulation	*simulation;
	pthread_t		thread;
	size_t			i;
	int				error_code;
	void			*exit_status;

	i = 0;
	simulation = data[i].simulation;
	while (i < simulation->philo_amount)
	{
		thread = simulation->philosophers[i].thread;
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
		i ++;
	}
}

void	ph_end_simulation(t_thread_data *data)
{
	t_simulation	*simulation;

	simulation = data[0].simulation;
	ph_join_threads(data);
	ph_destroy_mutexes(simulation);
	free(simulation->philosophers);
	free(data);
}
