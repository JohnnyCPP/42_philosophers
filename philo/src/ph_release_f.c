/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_release_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_release_f(pthread_mutex_t *l, pthread_mutex_t *r)
{
	int	error_code;

	error_code = pthread_mutex_unlock(l);
	if (error_code)
	{
		printf(ERROR_RELEASE_LEFT);
		error_code = 0;
	}
	error_code = pthread_mutex_unlock(r);
	if (error_code)
	{
		printf(ERROR_RELEASE_RIGHT);
		error_code = 0;
	}
}
