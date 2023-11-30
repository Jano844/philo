/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:25:23 by maburnet          #+#    #+#             */
/*   Updated: 2023/11/16 20:25:25 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_initialize_philo(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].eat_count = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->philo_nbr;
		data->philo[i].time_last_meal = 0;
		data->philo[i].data = data;
	}
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = data->philo_nbr;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (-1);
	}
	if (pthread_mutex_init(&(data->meal_check), NULL))
		return (-1);
	if (pthread_mutex_init(&(data->write), NULL))
		return (-1);
	if (pthread_mutex_init(&(data->dead_check), NULL))
		return (-1);
	if (pthread_mutex_init(&(data->all_ate_check), NULL))
		return (-1);
	if (pthread_mutex_init(&(data->eat_count_check), NULL))
		return (-1);
	return (0);
}

int	ft_initialize(t_data *data, char **argv)
{
	data->philo_nbr = ft_atol(argv[1]);
	data->t_t_die = ft_atol(argv[2]);
	data->t_t_eat = ft_atol(argv[3]);
	data->t_t_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->nb_of_time_eat = ft_atol(argv[5]);
	else
		data->nb_of_time_eat = -1;
	if (ft_init_mutex(data) == 1)
		return (-1);
	ft_initialize_philo(data);
	return (0);
}
