/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_not_finished.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_not_finished(t_simulation *simulation, size_t i)
{
	if (simulation->meals == MEALS_DEFAULT)
		return (FALSE);
	if (simulation->philosophers[i].meals_amount < simulation->meals)
		return (TRUE);
	return (FALSE);
}
