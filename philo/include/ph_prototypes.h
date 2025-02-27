/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PH_PROTOTYPES_H
# define PH_PROTOTYPES_H

/**
 * @brief Checks if a character is a digit.
 *
 * @param character The character.
 *
 * @return 1 if it's a digit, 0 if it's not.
 */
int		ft_isdigit(const char character);

/**
 * @brief Validates the string representation of an int against overflows.
 *
 * @param value The string representation of an integer value.
 *
 * @return If the value doens't trigger overflow against INT_MIN or INT_MAX,
 *         returns 0. Returns 1 for positive overflows,
 *         and -1 for negative overflows.
 */
int		ft_ioverflow(const char *value);

/**
 * @brief Validates the amount of arguments and their values.
 *
 * @param argc Argument count, represents the amount of arguments 
 *             passed to the program, including the program name.
 * @param argv Argument vector, a double pointer to the program arguments.
 *
 * Returns EXIT_SUCCESS if the argument amount is between MIN_ARGS 
 * and MAX_ARGS, and the times don't exceed integer limits.
 * Otherwise, returns EXIT_FAILURE.
 */
int		ph_validate_args(int argc, char **argv);

#endif
