/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:43:42 by acristin          #+#    #+#             */
/*   Updated: 2022/02/19 19:41:12 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_if_digit(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_uint(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 2147483647
			&& ft_strncmp(argv[i], "2147483647", 10))
			return (0);
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	(void) argv;
	if (argc != 5 && argc != 6)
		return (printf("Wrong number of argumens, should be 4 or 5\n") && 0);
	if (!check_if_digit(argc, argv))
		return (printf("Not a number amomg arguments\n") && 0);
	if (!check_if_uint(argc, argv))
		return (printf("Non valid numbers among arguments\n") && 0);
	return (1);
}

void	get_input(int argc, char **argv, t_info *main)
{
	main->num = ft_atoi(argv[1]);
	main->input.t2die = ft_atoi(argv[2]);
	main->input.t2eat = ft_atoi(argv[3]);
	main->input.t2sleep = ft_atoi(argv[4]);
	main->input.nmeals = -1;
	if (argc == 6)
		main->input.nmeals = ft_atoi(argv[5]);
}

void	copy_input(int argc, char **argv, t_philo *philo)
{
	philo->input.num = ft_atoi(argv[1]);
	philo->input.t2die = ft_atoi(argv[2]);
	philo->input.t2eat = ft_atoi(argv[3]);
	philo->input.t2sleep = ft_atoi(argv[4]);
	philo->input.nmeals = -1;
	if (argc == 6)
		philo->input.nmeals = ft_atoi(argv[5]);
}
