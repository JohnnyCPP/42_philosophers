/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_constants.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PH_CONSTANTS_H
# define PH_CONSTANTS_H

/**
 * @brief Application errors.
 */
# define ERROR_ARGC "Usage: ./philo <philos> <die> <eat> <sleep> ?<times>\n"
# define ERROR_NUMS "An error occurred processing time amounts.\n"

/**
 * @brief Status codes returned when a string would overflow an integer.
 */
# define POS_OFLOW 1
# define NEG_OFLOW -1

/**
 * @brief Expected amount of arguments.
 */
# define MIN_ARGS 5
# define MAX_ARGS 6

#endif
