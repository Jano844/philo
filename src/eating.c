/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:55:31 by jsanger           #+#    #+#             */
/*   Updated: 2024/01/16 21:58:57 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// current time in milliseconds
unsigned long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (error("Error, get time failed\n", NULL));
	return ((tv.tv_sec * (unsigned long long)1000) + (tv.tv_usec / 1000));
}

void	messages(char *str, t_philo *philo)
{
	unsigned long	time;

	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->start_time;
	if (ft_strcmp("died", str) == 0 && philo->data->dead == 0)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->data->dead = 1;
	}
	if (!philo->data->dead)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	messages("has taken a fork", philo);
	if (philo->data->philo_num == 1)
	{
		while (philo->data->done != 1)
			ft_usleep(1);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	messages("has taken a fork", philo);
	pthread_mutex_lock(&philo->lock);
	philo->last_meal = get_time();
	messages("is eating", philo);
	philo->eat_cont++;
	ft_usleep(philo->data->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->lock);
}
