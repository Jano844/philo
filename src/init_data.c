/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:06:26 by jsanger           #+#    #+#             */
/*   Updated: 2024/01/16 14:59:28 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_digit_or_sign(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (0);
	return (1);
}

int	input_checker(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[++i])
	{
		j = 0;
		while (input[i][j])
		{
			if (!is_digit_or_sign(input[i][j]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	init_data(t_data *data, char **argv, int argc)
{
	if (!input_checker(argv))
		return (error("Error, invalid input", NULL));
	data->philo_num = (int) ft_atoi(argv[1]);
	data->death_time = (unsigned long) ft_atoi(argv[2]);
	data->eat_time = (unsigned long) ft_atoi(argv[3]);
	data->sleep_time = (unsigned long) ft_atoi(argv[4]);
	if (argc == 6 && (int)ft_atoi(argv[5]) <= 0)
		return (error("Error, invalid input", NULL));
	if (argc == 6)
		data->meals_nb = (int) ft_atoi(argv[5]);
	else
		data->meals_nb = -1;
	if (data->philo_num <= 0 || data->philo_num > 200
		|| (long)data->death_time < 0
		|| (long)data->eat_time < 0 || (long)data->sleep_time < 0)
		return (error("Error, invalid input", NULL));
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}
