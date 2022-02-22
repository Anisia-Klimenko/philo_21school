/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:25:48 by acristin          #+#    #+#             */
/*   Updated: 2022/02/21 16:13:11 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (!go_eat(philo))
			break ;
		if (!go_sleep_think(philo))
			break ;
	}
	return (0);
}

int	manage_meals(t_info *main, int i)
{
	pthread_mutex_lock(&main->philos[i].mutex);
	if (main->philos[i].xate >= main->input.nmeals)
	{
		pthread_mutex_unlock(&main->philos[i].mutex);
		join_threads(main);
		return (1);
	}
	pthread_mutex_unlock(&main->philos[i].mutex);
	return (0);
}

void	check_death(t_info *main)
{
	int	i;

	i = 0;
	while (i <= main->num)
	{
		if (i == main->num)
			i = 0;
		if (ifdead(&main->philos[i]))
		{
			pthread_mutex_lock(main->philos[i].print);
			detach_threads(main);
			mysleep(1);
			printf("%lu %d died\n", get_time() - main->philos[i].starttime - 1,
				main->philos[i].id);
			return ;
		}
		else if (main->input.nmeals != -1)
		{
			if (manage_meals(main, i))
				return ;
		}
		i++;
	}
}

int	create_threads(t_info *main)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&main->print, NULL) != 0)
		return (0);
	while (i < main->num)
	{
		main->philos[i].print = &main->print;
		if (pthread_create(&main->philos[i].thread, NULL, &routine,
				(void *)&main->philos[i]))
			return (0);
		i++;
		usleep(1);
	}
	check_death(main);
	return (1);
}
