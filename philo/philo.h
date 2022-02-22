/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:40:49 by acristin          #+#    #+#             */
/*   Updated: 2022/02/21 15:54:52 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# include "src/libft/libft.h"

typedef struct s_input
{
	int				num;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	int				nmeals;
}	t_input;

typedef struct s_philo
{
	pthread_t		thread;
	t_input			input;
	int				id;
	int				xate;
	unsigned long	lasttime;
	unsigned long	starttime;
	int				leftfirst;
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
	pthread_mutex_t	*print;
	pthread_mutex_t	mutex;
}	t_philo;

typedef struct s_info
{
	int				num;
	int				ifdead;
	t_philo			*philos;
	t_input			input;
	unsigned long	starttime;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_info;

int				check_args(int argc, char **argv);
void			get_input(int argc, char **argv, t_info *main);
void			copy_input(int argc, char **argv, t_philo *philo);

// initialization
int				init_philos(t_info *main, int argc, char **argv);
int				init_forks(t_info *main);

// time
unsigned long	get_time(void);
void			mysleep(unsigned long ms);

// utils
void			free_philo(t_info *main);
void			print_philo(char *str1, char *str2, t_philo *philo);
int				count_meals(t_philo *philo);
int				ifdead(t_philo *philo);

// threads
int				create_threads(t_info *main);
int				detach_threads(t_info *main);
int				join_threads(t_info *main);

// routine
int				go_eat(t_philo *philo);
int				go_sleep_think(t_philo *philo);
int				go_think(t_philo *philo);

#endif