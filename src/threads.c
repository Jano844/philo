/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:55:44 by jsanger           #+#    #+#             */
/*   Updated: 2024/01/17 19:39:46 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping_and_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	messages("is sleeping", philo);
	ft_usleep(philo->data->sleep_time);
	pthread_mutex_unlock(&philo->lock);
	messages("is thinking", philo);
}

void	*surveillance(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)data_pointer;
	while (philo->data->done == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->philo_num)
			philo->data->done = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

void	checker(t_data *data)
{
	int			i;
	long long	time;

	while (data->done != 1)
	{
		if (data->finished >= data->philo_num)
		{
			data->done = 1;
			return ;
		}
		i = -1;
		while (++i < data->philo_num)
		{
			time = get_time() - data->philos[i].last_meal;
			if (time >= (long long)data->death_time)
			{
				messages("died", &data->philos[i]);
				data->done = 1;
				return ;
			}
		}
		if (data->done == 1)
			return ;
	}
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (philo->data->done != 1)
	{
		if (philo->eat_cont == philo->data->meals_nb)
			philo->data->finished++;
		eat(philo);
		sleeping_and_thinking(philo);
	}
	return (NULL);
}

int	threads(t_data *data, int i)
{
	pthread_t	thread;

	i = -1;
	data->start_time = get_time();
	if (data->meals_nb > 0)
	{
		if (pthread_create(&thread, NULL, &surveillance, &data->philos[0]))
			return (error("Error creating threads", data));
	}
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (error("Error creating threads", data));
		usleep(100);
	}
	checker(data);
	i = -1;
	if (pthread_join(thread, NULL))
		return (error("Error joining threads", data));
	while (++i < data->philo_num)
	{
		if (pthread_join(data->tid[i], NULL))
			return (error("Error joining threads", data));
	}
	return (0);
}
