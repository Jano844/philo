/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:55:10 by jsanger           #+#    #+#             */
/*   Updated: 2024/01/18 02:59:42 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Test 1 800 200 200. The philosopher should not eat and should die.
// Test 5 800 200 200. No philosopher should die.
// Test 5 800 200 200 7 No philosopher should die, 7 meals.
// Test 4 410 200 200. No philosopher should die.
// Test 4 310 200 100. One philosopher should die.

// philo does routine
// picks up one fork, cant pick um an other, because there is only one
// philo waits until he is dead
// thread gets detached.

void	init_struct(t_data *data)
{
	data->philo_num = 0;
	data->meals_nb = 0;
	data->finished = 0;
	data->done = 0;
	data->death_time = 0;
	data->eat_time = 0;
	data->sleep_time = 0;
	data->start_time = 0;
}

int	only_one_philo(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (error("Error creating threads", data));
	checker(data);
	ft_exit(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	init_struct(data);
	if (argc != 5 && argc != 6)
	{
		printf("Invalid numer of arguments\n");
		return (1);
	}
	if (init(data, argv, argc))
	{
		free(data);
		return (1);
	}
	if (data->philo_num == 1)
		return (only_one_philo(data));
	if (threads(data, 0))
		return (1);
	ft_exit(data);
	return (0);
}
