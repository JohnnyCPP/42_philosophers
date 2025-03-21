/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argc, char **argv)
{
	t_thread_data	*data;
	t_simulation	simulation;

	if (ph_validate_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ph_parse_arguments(argc, argv, &simulation);
	if (ph_allocate_philo_memory(&simulation) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ph_initialize_mutexes(&simulation) == EXIT_FAILURE)
	{
		free(simulation.philosophers);
		return (EXIT_FAILURE);
	}
	if (ph_allocate_thread_data(&data, &simulation) == EXIT_FAILURE)
	{
		ph_destroy_mutexes(&simulation);
		free(simulation.philosophers);
		return (EXIT_FAILURE);
	}
	if (ph_run_threads(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ph_start_simulation(data);
	ph_end_simulation(data);
	return (EXIT_SUCCESS);
}
