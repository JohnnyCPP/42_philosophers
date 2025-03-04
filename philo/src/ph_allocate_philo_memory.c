/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_allocate_philo_memory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_allocate_philo_memory(t_simulation *simulation)
{
	size_t	amount;
	size_t	size;

	amount = simulation->philo_amount;
	size = sizeof(t_philosopher);
	simulation->philosophers = (t_philosopher *) ft_calloc(amount, size);
	if (!simulation->philosophers)
	{
		printf(ERROR_MEMORY);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
