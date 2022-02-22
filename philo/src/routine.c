/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:43:38 by acristin          #+#    #+#             */
/*   Updated: 2022/02/21 16:03:27 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	go_sleep_think(t_philo *philo)
{
	if (philo->input.nmeals > 0 && !count_meals(philo))
		return (0);
	print_philo("is sleeping", NULL, philo);
	mysleep(philo->input.t2sleep);
	print_philo("is thinking", NULL, philo);
	return (1);
}

int	take_forks(t_philo *philo)
{
	if (philo->input.nmeals > 0 && !count_meals(philo))
		return (0);
	if (philo->leftfirst)
	{
		pthread_mutex_lock(philo->leftfork);
		print_philo("has taken a fork", NULL, philo);
		pthread_mutex_lock(philo->rightfork);
	}
	else
	{
		pthread_mutex_lock(philo->rightfork);
		print_philo("has taken a fork", NULL, philo);
		pthread_mutex_lock(philo->leftfork);
	}
	print_philo("has taken a fork", "is eating", philo);
	return (1);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->leftfork);
	pthread_mutex_unlock(philo->rightfork);
}

int	go_eat(t_philo *philo)
{
	usleep(1);
	if (!take_forks(philo))
		return (0);
	pthread_mutex_lock(&philo->mutex);
	philo->xate++;
	philo->lasttime = get_time();
	pthread_mutex_unlock(&philo->mutex);
	mysleep(philo->input.t2eat);
	drop_forks(philo);
	return (1);
}
