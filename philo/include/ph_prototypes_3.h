/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_prototypes_3.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 17:06:52 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PH_PROTOTYPES_3_H
# define PH_PROTOTYPES_3_H

/**
 * @brief Lock left and right forks, in this order.
 */
int	ph_g_f_l(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r, int err);

/**
 * @brief Lock right and left forks, in this order.
 */
int	ph_g_f_r(t_thread_data *d, pthread_mutex_t *l, pthread_mutex_t *r, int err);

#endif
