/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:47:33 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 13:22:49 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void clean_threads(t_philos *philos, int created_count)
{
    int i;

    i = 0;
    while (i < created_count)
        pthread_join(philos[i++].thread, NULL);
}

int  launch_threads(t_data *data, t_philos **philos)
{
    pthread_t   monitor;
    int         i;
    int         ret;

    i = 0;
    while (i < data->number_of_philos)
    {
        ret = pthread_create(&(*philos)[i].thread, NULL, philosopher_routine, &(*philos)[i]);
        if (ret != 0)
            return (clean_threads(*philos, i), 0);
        i++;
    }
    ret = pthread_create(&monitor, NULL, monitor_routine, *philos);
    if (ret != 0)
        return (clean_threads(*philos, data->number_of_philos), 0);
    i = 0;
    while (i < data->number_of_philos)
        pthread_join((*philos)[i++].thread, NULL);
    pthread_join(monitor, NULL);
    return (1);
}
