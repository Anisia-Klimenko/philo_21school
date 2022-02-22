/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:56:27 by acristin          #+#    #+#             */
/*   Updated: 2022/02/21 16:10:56 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	count_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->xate >= philo->input.nmeals)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->mutex);
	return (1);
}

int	ifdead(t_philo *philo)
{
	unsigned long	now;

	now = get_time();
	pthread_mutex_lock(&philo->mutex);
	if (now - philo->lasttime > philo->input.t2die)
	{
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

int	detach_threads(t_info *main)
{
	int	i;

	i = 0;
	while (i < main->num)
	{
		if (pthread_detach(main->philos[i].thread) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	join_threads(t_info *main)
{
	int	i;

	i = 0;
	while (i < main->num)
	{
		if (pthread_join(main->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
