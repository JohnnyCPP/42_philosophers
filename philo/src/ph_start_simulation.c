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

void	ph_start_simulation(t_thread_data *data)
{
	t_simulation	*simulation;
	size_t			i;
	int				finished_eating;

	simulation = data[0].simulation;
	while (simulation->all_alive)
	{
		i = 0;
		finished_eating = TRUE;
		while (i < simulation->philo_amount)
		{
			if (ph_philo_starved(simulation, i))
			{
				ph_display_status(&data[i], STATUS_DIED);
				ph_kill_philosopher(simulation, i);
				break ;
			}
			if (ph_not_finished(simulation, i))
				finished_eating = FALSE;
			i ++;
		}
		if (simulation->meals != MEALS_DEFAULT && finished_eating)
			simulation->all_ate = TRUE;
	}
}
