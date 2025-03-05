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
# define ERROR_NUMS "Argument validation was unsuccessful.\n"
# define ERROR_MEMORY "An error occurred allocating memory for philosophers.\n"
# define ERROR_DATA_MEM "Error allocating memory for thread data.\n"
# define ERROR_THREAD "Error creating a thread: error code %i.\n"
# define ERROR_MUTEX "Error initializing a mutex: error code %i.\n"
# define ERROR_MUTEX_DESTROY "Error destroying a mutex: error code %i.\n"
# define ERROR_TIME "An error occurred getting the simulation start time.\n"
# define ERROR_CURRENT_TIME "An error occurred getting the current time.\n"
# define ERROR_MEAL_TIME "An error occurred updating the meal time.\n"
# define ERROR_GET_FORKS "Error attempting to get the forks.\n"
# define ERROR_LEFT_FORK "Error attempting to get the left fork.\n"
# define ERROR_RIGHT_FORK "Error attempting to get the right fork.\n"
# define ERROR_RELEASE_FORKS "Error attempting to release the forks.\n"
# define ERROR_RELEASE_LEFT "Error attempting to release the left fork.\n"
# define ERROR_RELEASE_RIGHT "Error attempting to release the right fork.\n"
# define ERROR_LOCK_DISPLAY "Error locking display status.\n"
# define ERROR_UNLOCK_DISPLAY "Error unlocking display status.\n"
# define ERROR_WAIT "Error trying to wait a given amount of time.\n"
# define ERROR_JOIN "Error joining a thread: error code %i.\n"
# define ERROR_STATUS_CODE "Thread returned exit status %ld.\n"

/**
 * @brief Philosopher statuses.
 *
 * The leftmost format specifier represents the time in milliseconds.
 * The one next to it represents the number of a philosopher.
 */
# define STATUS_TOOK_FORK "%lld %zu has taken a fork\n"
# define STATUS_IS_EATING "%lld %zu is eating\n"
# define STATUS_IS_SLEEPING "%lld %zu is sleeping\n"
# define STATUS_IS_THINKING "%lld %zu is thinking\n"
# define STATUS_DIED "%lld %zu died\n"

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

/**
 * @brief Index of arguments expected by the program.
 */
# define ARG_PHILOSOPHERS 1
# define ARG_DIE_TIME 2
# define ARG_EAT_TIME 3
# define ARG_SLEEP_TIME 4
# define ARG_EAT_AMOUNT 5

/**
 * @brief Default value of meals.
 */
# define MEALS_DEFAULT -1

/**
 * @brief Used to make infinite loops verbose.
 *
 * Also used for meal statuses.
 */
# define TRUE 1
# define FALSE 0

/**
 * @brief References the next philosopher.
 */
# define NEXT 1

/**
 * @brief Amount of microseconds in a millisecond.
 *
 * Used to wait n milliseconds using "usleep()".
 */
# define MICROSECONDS_IN_A_MILLISECOND 1000

/**
 * @brief Amount of milliseconds in a second.
 *
 * Used to convert seconds to milliseconds.
 */
# define MILLISECONDS_IN_A_SECOND 1000

/**
 * @brief Amount of microseconds in a second.
 *
 * Used to address the case when "final.tv_usec" 
 * is smaller than "start.tv_usec".
 */
# define MICROSECONDS_IN_A_SECOND 1000000

/**
 * @brief Case when the user introduces an amount of 0 philosophers.
 */
# define ZERO_PHILOSOPHERS 0

/**
 * @brief Used to set an error/status code variable to zero.
 *
 * This is useful in loops when an error code returning function 
 * is called many times, allowing to update the variable more than once.
 *
 * In cases like these, the error code variable is set to zero, and 
 * this constant makes it more verbose.
 */
# define RESET_ERROR_CODE 0
# define RESET_STATUS_CODE 0

/**
 * @brief Returned value from a thread when ended successfully.
 */
# define THREAD_EXIT_SUCCESS 2

/**
 * @brief Returned value from ph_get_delta_time() when an error occurs.
 */
# define DELTA_TIME_FAILURE -1

/**
 * @brief Amount of meals set when the simulation starts.
 */
# define STARTING_MEALS_AMOUNT 0

/**
 * @brief Good philo, dead philo.
 */
# define STATUS_ALIVE 0
# define STATUS_DEAD 1

#endif
