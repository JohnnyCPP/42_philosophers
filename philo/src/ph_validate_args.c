/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	ph_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (EXIT_FAILURE);
		i ++;
	}
	return (EXIT_SUCCESS);
}

static int	ph_validate_numbers(int argc, char **argv)
{
	int	arg;
	int	status_code;

	arg = 1;
	status_code = 0;
	while (arg < argc)
	{
		status_code = ft_ioverflow(argv[arg]);
		if (status_code == POS_OFLOW || status_code == NEG_OFLOW)
			return (EXIT_FAILURE);
		if (ph_is_number(argv[arg]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		arg ++;
	}
	return (EXIT_SUCCESS);
}

int	ph_validate_args(int argc, char **argv)
{
	if (argc < MIN_ARGS)
	{
		printf(ERROR_ARGC);
		return (EXIT_FAILURE);
	}
	else if (argc > MAX_ARGS)
	{
		printf(ERROR_ARGC);
		return (EXIT_FAILURE);
	}
	if (ph_validate_numbers(argc, argv) == EXIT_FAILURE)
	{
		printf(ERROR_NUMS);
		return (EXIT_FAILURE);
	}
	if (ft_atoi(argv[ARG_PHILOSOPHERS]) == ZERO_PHILOSOPHERS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
