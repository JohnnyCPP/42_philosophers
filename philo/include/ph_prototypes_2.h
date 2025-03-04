/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_prototypes_2.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PH_PROTOTYPES_2_H
# define PH_PROTOTYPES_2_H

/**
 * @brief Gets the interval of milliseconds passed from the beginning.
 *
 * @param simulation The simulation context, containing time intervals.
 *
 * @return The amount of milliseconds passed. If an error occurs trying to
 *         get the current time, returns DELTA_TIME_FAILURE.
 *
 * This function also updates the "current_time" member of the simulation.
 */
long long	ph_get_delta_time(t_simulation *simulation);

#endif
