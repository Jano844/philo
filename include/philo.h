/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:56:19 by jsanger           #+#    #+#             */
/*   Updated: 2024/01/17 23:19:11 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_data	*data;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				id;
	int				eat_cont;
	unsigned long	last_meal;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	t_philo			*philos;
	int				philo_num;
	int				meals_nb;
	int				finished;
	int				done;
	unsigned long	death_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	start_time;
}	t_data;

// error / exit
void			ft_exit(t_data *data);
int				error(char *str, t_data *data);

// init
int				init(t_data *data, char **argv, int argc);
int				init_data(t_data *data, char **argv, int argc);
int				threads(t_data *data, int i);
int				input_checker(char **argv);

// treads
unsigned long	get_time(void);
int				ft_usleep(unsigned long time);
void			eat(t_philo *philo);
void			*routine(void *philo_pointer);
void			checker(t_data *data);

// utils
long			ft_atoi(const char *str);
int				ft_strcmp(char *s1, char *s2);
void			messages(char *str, t_philo *philo);
void			ft_exit(t_data *data);

#endif