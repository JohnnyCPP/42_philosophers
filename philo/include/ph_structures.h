/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PH_STRUCTURES_H
# define PH_STRUCTURES_H

/**
 * @brief Represents a philosopher of a simulation.
 *
 * "fork" is a resource used to determine mutual exclusion.
 */
typedef struct s_philosopher
{
	struct timeval	meal_time;
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				meals_amount;
	int				is_dead;
}				t_philosopher;

/**
 * @brief Represents required data for a simulation of philosophers.
 *
 * "philosophers" is the amount of philosophers around the table.
 * "die_time" is the amount of time that a philosopher can stand 
 *            without eating.
 * "eat_time" is the amount of time a philosopher takes to eat.
 * "sleep_time" is the amount of time a philosopher takes to sleep.
 * "meals" is the amount of times each philosopher needs to eat 
 *         to finish the simulation. This member is optional. If this 
 *         member is not specified, the simulation only ends when 
 *         a philosopher starves
 *
 * Time periods are in milliseconds.
 */
typedef struct s_simulation
{
	size_t			philo_amount;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals;
	struct timeval	start_time;
	struct timeval	current_time;
	t_philosopher	*philosophers;
	pthread_mutex_t	attempt_to_forks;
	pthread_mutex_t	attempt_to_print;
	int				all_alive;
	int				all_ate;
}				t_simulation;

/**
 * @brief Data passed to the thread function of a given philosopher.
 */
typedef struct s_thread_data
{
	size_t			philosopher;
	t_simulation	*simulation;
}				t_thread_data;

#endif
