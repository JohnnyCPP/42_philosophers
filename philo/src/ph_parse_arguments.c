/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_parse_arguments(int argc, char **argv, t_simulation *simulation)
{
	simulation->philo_amount = (size_t) ft_atoi(argv[ARG_PHILOSOPHERS]);
	simulation->die_time = ft_atoi(argv[ARG_DIE_TIME]);
	simulation->eat_time = ft_atoi(argv[ARG_EAT_TIME]);
	simulation->sleep_time = ft_atoi(argv[ARG_SLEEP_TIME]);
	if (argc == MAX_ARGS)
		simulation->meals = ft_atoi(argv[ARG_EAT_AMOUNT]);
	else
		simulation->meals = MEALS_DEFAULT;
}
