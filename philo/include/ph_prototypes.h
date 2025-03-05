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
 * @brief Joins all threads, deletes mutexes, and frees heap memory.
 *
 * @param data Structure containing the philosophers and app context.
 */
void	ph_end_simulation(t_thread_data *data);

/**
 * @brief Checks if a philosopher is still eating.
 *
 * @param simulation Structure containing the philosophers.
 * @param i Index of the specific philosopher to check to.
 *
 * @return TRUE if "meals_amount" is less than "meals".
 *         FALSE if "meals" equals MEALS_DEFAULT, or if 
 *         "meals_amount" is equal to or greater than "meals".
 *
 * "meals_amount" represents the amount of times a philosopher has eatten.
 * "meals" determines the amount of meals all philosophers must have 
 * to end the simulation.
 * MEALS_DEFAULT is the value of "meals" when the optional parameter is 
 * not specified. If "meals" equals MEALS_DEFAULT, philosophers will 
 * continue the simulation until one starves.
 */
int		ph_not_finished(t_simulation *simulation, size_t i);

/**
 * @brief Kills a philosopher.
 *
 * @param simulation Structure containing the philosophers.
 * @param i Index of the specific philosopher to kill.
 *
 * This function will set "all_alive" to FALSE, terminating all threads.
 */
void	ph_kill_philosopher(t_simulation *simulation, size_t i);

/**
 * @brief Checks if a philosopher starved.
 *
 * @param simulation Structure containing the philosophers.
 * @param i Index of the specific philosopher to check to.
 *
 * @return 0 if the philosopher doesn't starve.
 *         A non-zero value if it does.
 */
int		ph_philo_starved(t_simulation *simulation, size_t i);

/**
 * @brief Loops checking if a philosopher dies or all finished eating.
 *
 * @param data Structure containing the philosophers and app context.
 *
 * Stops when a philosopher dies or when the meals condition is met.
 */
void	ph_start_simulation(t_thread_data *data);

/**
 * @brief Updates the time by which a given philosopher ate.
 *
 * @param philosopher The philosopher to update meal time to.
 */
void	ph_update_meal_time(t_philosopher *philosopher);

/**
 * @brief Checks if a character is a plus or minus sign.
 *
 * @param character The character.
 *
 * @return 1 if it's a sign, 0 if it's not.
 */
int		ft_issign(const char character);

/**
 * @brief Checks if a character is a space.
 *
 * @param character The character.
 *
 * @return 1 if it's a space, 0 if it's not.
 */
int		ft_isspace(const char character);

/**
 * @brief Prints a status message on the terminal, for a given philosopher.
 *
 * @param data Thread data structure containing the philosopher number.
 * @param format The format string to be printed.
 *
 * If an error occurs attempting to get the current time, exits silently.
 */
void	ph_display_status(t_thread_data *data, const char *format);

/**
 * @brief Allocates a block of memory for a t_thread_data structure.
 *
 * @param data A double pointer to the structure to allocate.
 * @param sim The simulation context.
 *
 * @return EXIT_SUCCESS if the allocation was successful.
 *         EXIT_FAILURE if "data" is not a valid pointer, or 
 *         the allocation was unsuccessful.
 *
 * The allocated block of memory will be of "philo_amount" length.
 * This function will also populate the block of memory, assigning the 
 * "philosopher" number to each structure, and the simulation context 
 * to the "simulation" member.
 */
int		ph_allocate_thread_data(t_thread_data **data, t_simulation *sim);

/**
 * @brief Waits a given amount of milliseconds.
 *
 * @param ms Amount of milliseconds to wait.
 *
 * @return Always EXIT_SUCCESS.
 */
int		ph_wait_ms(int ms);

/**
 * @brief Destroys only the mutexes related to the forks.
 *
 * @param simulation Structure containing the mutexes to be destroyed.
 */
void	ph_destroy_philo_mutexes(t_simulation *simulation);

/**
 * @brief Destroys all mutexes.
 *
 * @param simulation Structure containing the mutexes to be destroyed.
 */
void	ph_destroy_mutexes(t_simulation *simulation);

/**
 * @brief Makes philosophers eat, sleep, and think.
 *
 * @param data Is a pointer to the thread data.
 *
 * @return EXIT_SUCCESS if no error occurred. Otherwise, EXIT_FAILURE.
 *
 * This function creates a thread for each philosopher, whose calling 
 * function is "ph_philo_actions()".
 *
 * Note that this function also computes the start time of the simulation, 
 * since it should start as close as the first thread is created.
 */
int		ph_run_threads(t_thread_data *data);

/**
 * @brief A philosopher eats, sleeps, and finally thinks.
 *
 * @param arg Is a pointer to a "t_thread_data" struct.
 *
 * @return EXIT_SUCCESS casted to a pointer to void if success.
 *         EXIT_FAILURE casted to a pointer to void, in case of error.
 *
 * The "t_thread_data" struct contains the simulation context and 
 * the number of philosopher.
 */
void	*ph_philo_actions(void *arg);

/**
 * @brief Initializes mutexes (forks) and handles errors.
 *
 * @param simulation Structure containing the philosophers and their forks.
 *
 * @return EXIT_SUCCESS if success, EXIT_FAILURE if an error occurs.
 */
int		ph_initialize_mutexes(t_simulation *simulation);

/**
 * @brief Allocates memory for philosophers in a simulation.
 *
 * @param simulation Structure containing the philosophers to allocate.
 *
 * @return EXIT_SUCCESS if allocation was a success, EXIT_FAILURE otherwise.
 */
int		ph_allocate_philo_memory(t_simulation *simulation);

/**
 * @brief Allocates memory for an array and initializes all bytes to zero.
 *
 * @param amount The number of elements to allocate.
 * @param size The size of each element in bytes.
 *
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t amount, size_t size);

/**
 * @brief Fills starting values of the simulation.
 *
 * @param argc Argument count, represents the amount of arguments 
 *             passed to the program, including the program name.
 * @param argv Argument vector, a double pointer to the program arguments.
 * @param simulation Structure used to store data used through the simulation.
 */
void	ph_parse_arguments(int argc, char **argv, t_simulation *simulation);

/**
 * @brief Converts a string to an integer.
 *
 * @param value A pointer to the string containing the number to be converted.
 *
 * @return The integer value represented by the string,
 *         or 0 if the string doesn't contain a valid number.
 *
 * This function converts the initial portion of the string pointed to
 * by "value" to an integer. It handles optional leading spaces,
 * an optional sign ('+' or '-'), and numeric characters.
 */
int		ft_atoi(const char *value);

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
