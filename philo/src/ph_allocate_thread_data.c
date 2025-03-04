/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_allocate_thread_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static	void	ph_assign_data(t_thread_data *data, t_simulation *simulation)
{
	size_t	i;

	i = 0;
	while (i < simulation->philo_amount)
	{
		data[i].philosopher = i;
		data[i].simulation = simulation;
		i ++;
	}
}

int	ph_allocate_thread_data(t_thread_data **data, t_simulation *sim)
{
	size_t	amount;
	size_t	size;

	if (!data)
		return (EXIT_FAILURE);
	amount = sim->philo_amount;
	size = sizeof(t_thread_data);
	*data = (t_thread_data *) ft_calloc(amount, size);
	if (!*data)
	{
		printf(ERROR_DATA_MEM);
		return (EXIT_FAILURE);
	}
	ph_assign_data(*data, sim);
	return (EXIT_SUCCESS);
}
