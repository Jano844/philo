/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:55:44 by jsanger           #+#    #+#             */
/*   Updated: 2023/12/09 14:11:51 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*surveillance(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->philo_num)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

// checker: a extra thread for every philo gets created
// this function checks weather a philo has died or has finished his meal

void	*checker(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
		{
			messages("died", philo);
			pthread_mutex_unlock(&philo->lock);
			return (NULL);
		}
		if (philo->eat_cont == philo->data->meals_nb)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_cont++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

// every thread creates a subthread so all
//philos are calling the supervison function
// function checks for each philo wheater he died or not,
// if one is dead the while loop below breaks and the function returns NULL
// eat while loop:
// overall execution of the philos life
//pthread join
//wait for created threads on checker
// if (philo->id % 2)
// 	usleep(1000);
// else
// 	usleep(500)

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->data->death_time + get_time();
	if (pthread_create(&philo->thread_checker, NULL, &checker, (void *)philo))
		return ((void *)1);
	while (philo->data->dead == 0
		&& (philo->data->meals_nb || philo->eat_cont < philo->data->meals_nb))
	{
		eat(philo);
		messages("is thinking", philo);
	}
	if (pthread_join(philo->thread_checker, NULL))
		return ((void *)1);
	return (NULL);
}
// creating threads
// only first philo does the monitoring function
// all threads for each philo one 
// are created and all philos start in the routine function.
// it waits for all philos to bie finished

int	threads(t_data *data)
{
	int			i;
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
		ft_usleep(2);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_join(data->tid[i], NULL))
			return (error("Error joining threads", data));
	}
	return (0);
}
