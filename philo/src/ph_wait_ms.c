/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_wait_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 17:18:23 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_wait_ms(int ms, t_thread_data *data)
{
	int	error_code;

	while (ms > 0)
	{
		if (!data->simulation->all_alive || data->simulation->all_ate)
			return (EXIT_SUCCESS);
		error_code = usleep(MICROSECONDS_IN_A_MILLISECOND);
		if (error_code)
		{
			printf(ERROR_WAIT);
			error_code = RESET_ERROR_CODE;
		}
		ms --;
	}
	return (EXIT_SUCCESS);
}
