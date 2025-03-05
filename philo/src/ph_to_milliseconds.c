/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_to_milliseconds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long long	ph_to_milliseconds(long long s, long long microseconds)
{
	long long	s_to_ms;
	long long	microseconds_to_ms;

	s_to_ms = s * MILLISECONDS_IN_A_SECOND;
	microseconds_to_ms = microseconds / MICROSECONDS_IN_A_MILLISECOND;
	return (s_to_ms + microseconds_to_ms);
}
