/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:40:34 by acristin          #+#    #+#             */
/*   Updated: 2022/02/21 16:13:37 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	one_philo(t_info *main)
{
	unsigned long	now;

	if (pthread_mutex_init(&main->print, NULL) != 0)
		return (0);
	now = get_time();
	printf("%lu %d has taken a fork\n", now - main->starttime,
		main->philos[0].id);
	mysleep(main->philos[0].input.t2die);
	printf("%lu %d died\n", get_time() - main->starttime, main->philos[0].id);
	free_philo(main);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	main;

	if (!check_args(argc, argv))
		return (1);
	get_input(argc, argv, &main);
	if (!init_philos(&main, argc, argv) || !init_forks(&main))
	{
		free_philo(&main);
		return (1);
	}
	if (main.philos[0].input.num == 1)
	{
		if (!one_philo(&main))
		{
			free_philo(&main);
			return (1);
		}
	}
	else
	{
		create_threads(&main);
		free_philo(&main);
		return (1);
	}
	return (0);
}
