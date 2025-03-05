/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_simulate(t_thread_data *data, t_simulation *sim, size_t i, int end)
{
	i = 0;
	end = TRUE;
	while (i < sim->philo_amount)
	{
		if (ph_philo_starved(sim, i))
		{
			ph_display_status(&data[i], STATUS_DIED);
			ph_kill_philosopher(sim, i);
			return (EXIT_FAILURE);
		}
		if (ph_not_finished(sim, i))
			end = FALSE;
		i ++;
	}
	if (sim->meals != MEALS_DEFAULT && end)
	{
		sim->all_ate = TRUE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ph_start_simulation(t_thread_data *data)
{
	t_simulation	*simulation;
	size_t			i;
	int				end;

	i = 0;
	end = 0;
	simulation = data[i].simulation;
	while (simulation->all_alive)
		if (ph_simulate(data, simulation, i, end) == EXIT_FAILURE)
			break ;
}
