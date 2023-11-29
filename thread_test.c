/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:50:42 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/29 23:15:41 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct	s_philo
{
	pthread_t	*thread;
	int			forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			rounds;
} 				t_philo;

void ft_init_struct(int argc, char **argv, t_philo *philo)
{
	int i;

	i = 1;
	philo->forks = atoi(argv[i++]);
	philo->time_to_die = atoi(argv[i++]);
	philo->time_to_eat = atoi(argv[i++]);
	philo->time_to_sleep = atoi(argv[i++]);
	philo->rounds = atoi(argv[i]);
}

void *routine()
{
	printf("HelloWorld\n");
	return NULL;
}

int main(int argc, char **argv)
{
	t_philo *philo;
	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments!\n");
		return 1;
	}
	philo = (t_philo *)malloc(sizeof(t_philo));

	ft_init_struct(argc, argv, philo);

	philo->thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->forks);
	if (philo->thread == NULL)
	{
		printf("Memory allocation error!\n");
		free(philo);
		return 1;
	}

	for (int i = 0; i < philo->forks; i++)
	{
		if (pthread_create(&philo->thread[i], NULL, routine, NULL) != 0)
			return 1;
	}

	for (int i = 0; i < philo->forks; i++)
	{
		if (pthread_join(philo->thread[i], NULL) != 0)
			return 2;
	}

	free(philo->thread);
	free(philo);

	return 0;
}

