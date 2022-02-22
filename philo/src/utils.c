/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:48:38 by acristin          #+#    #+#             */
/*   Updated: 2022/02/21 16:11:43 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philos(t_info *main, int argc, char **argv)
{
	int	i;

	i = 0;
	(void) argc;
	(void) argv;
	main->starttime = get_time();
	main->philos = malloc(sizeof(t_philo) * main->num);
	if (!main->philos)
		return (0);
	while (i < main->num)
	{
		main->philos[i].id = i + 1;
		main->philos[i].xate = 0;
		main->philos[i].starttime = main->starttime;
		main->philos[i].lasttime = main->starttime;
		main->philos[i].leftfirst = i % 2;
		pthread_mutex_init(&main->philos[i].mutex, NULL);
		copy_input(argc, argv, &main->philos[i]);
		i++;
	}
	return (1);
}

int	init_forks(t_info *main)
{
	int	i;

	i = 1;
	main->forks = malloc(sizeof(pthread_mutex_t) * main->num);
	if (!main->forks)
		return (0);
	pthread_mutex_init(&main->forks[0], NULL);
	main->philos[0].rightfork = &main->forks[0];
	while (i < main->num)
	{
		pthread_mutex_init(&main->forks[i], NULL);
		main->philos[i].rightfork = &main->forks[i];
		main->philos[i].leftfork = &main->forks[i - 1];
		i++;
	}
	main->philos[0].leftfork = &main->forks[i - 1];
	return (1);
}

void	free_philo(t_info *main)
{
	if (main->philos != NULL)
		free(main->philos);
	if (main->forks != NULL)
		free(main->forks);
}

void	print_philo(char *str1, char *str2, t_philo *philo)
{
	int	now;

	now = get_time() - philo->starttime;
	pthread_mutex_lock(philo->print);
	if (!str2)
		printf("%d %d %s\n", now, philo->id, str1);
	else
		printf("%d %d %s\n%d %d %s\n", now, philo->id, str1, now,
			philo->id, str2);
	pthread_mutex_unlock(philo->print);
}
