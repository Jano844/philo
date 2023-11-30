/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:51:49 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/30 15:10:30 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
#include <pthread.h>
# include "../libft/libft.h"

typedef struct	s_philo
{
	pthread_t	*thread;
	int			forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			rounds;
} 				t_philo;

// typedef struct s_philo
// {
//     int id;
//     pthread_t thread;
//     struct s_data *data;
// } t_philo;

// typedef struct s_data
// {
//     pthread_mutex_t *mutex;
//     pthread_mutex_t common_mutex;
// } t_data;
#endif