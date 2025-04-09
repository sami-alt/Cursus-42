/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 09:50:51 by sraiha            #+#    #+#             */
/*   Updated: 2025-04-09 09:50:51 by sraiha           ###   ########fii       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    free_resources(t_data *data, t_philosophers *philosophers)
{
    int i;

    i = 0;
    while ( i < data->number_of_philos )
        pthread_mutex_destroy(&data->forks[i++]);
    pthread_mutex_destroy(&data->lock);
    free(data->forks);
    free(philosophers);
}

static void clean_exit(t_data *data, t_philosophers *philos, int exit_code)
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
    pthread_mutex_destroy(&data->lock);
    pthread_mutex_destroy(&data->death_lock);
    exit(exit_code);
}