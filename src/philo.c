/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:50:29 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/30 15:09:34 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void eat(t_philo *philo, t_data *data)
{
    pthread_mutex_lock(&data->common_mutex);
    printf("%d STARTEN\n", philo->id);
    usleep(1000 * 1000);
    printf("%d FERTIG\n", philo->id);
    pthread_mutex_unlock(&data->common_mutex);
}

void *selector(void *data)
{
    t_philo *philo = data;
    t_data *data1 = philo->data;

    while (1)
    {
        eat(philo, data1);
        usleep(1000 * 1000);
    }
    return NULL;
}

void thread_handler()
{
    t_philo *philo = malloc(sizeof(t_philo) * 3);

    t_data data;
    data.mutex = malloc(sizeof(pthread_mutex_t) * 3);

    // Initialize the common mutex
    pthread_mutex_init(&data.common_mutex, NULL);

    int i = 0;
    while (i < 3)
    {
        pthread_mutex_init(&data.mutex[i], NULL);
        i++;
    }

    i = 0;
    while (i < 3)
    {
        philo[i].id = i + 1;
        philo[i].data = &data;

        i++;
    }

    i = -1;
    while (++i < 3)
    {
        if (i % 2)
            usleep(1000);
        else
            usleep(500);
        pthread_create(&philo[i].thread, NULL, selector, &philo[i]);
    }
    i = -1;
    while (++i < 3)
        pthread_join(philo[i].thread, NULL);

    // Destroy the common mutex
    pthread_mutex_destroy(&data.common_mutex);

    free(philo);
    free(data.mutex);
}


int	main(int argc, char **argv)
{
	// if (argc != 5 && argc != 6)
	// {
	// 	printf("Too few arguments\n");
	// 	return (1);
	// }
	thread_handler();
}
