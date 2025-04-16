/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:50:51 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 13:19:32 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    free_resources(t_data *data, t_philos *philos)
{
    int i;

    i = 0;
    while ( i < data->number_of_philos )
        pthread_mutex_destroy(&data->forks[i++]);
    pthread_mutex_destroy(&data->write_lock);
    free(data->forks);
    free(philos);
}

void clean_exit(t_data *data, t_philos *philos, int exit_code)
{
    int i;

    if (philos)
    {
        i = 0;
        while (i < data->number_of_philos)
        {
            pthread_mutex_destroy(&data->forks[i]);
            i++;
        }
        free(data->forks);
        free(philos);
    }
    pthread_mutex_destroy(&data->write_lock);
    pthread_mutex_destroy(&data->death_lock);
    exit(exit_code);
}