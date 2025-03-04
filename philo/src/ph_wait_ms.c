/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_wait_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ph_wait_ms(int ms)
{
	int	error_code;

	while (ms > 0)
	{
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
