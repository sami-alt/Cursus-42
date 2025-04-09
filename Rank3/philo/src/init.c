/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-07 08:43:20 by sraiha            #+#    #+#             */
/*   Updated: 2025-04-07 08:43:20 by sraiha           ###   ########fii       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int     parse_args(int ac,char **av, t_data *data)
{   
    data->number_of_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->max_meals = ft_atoi(av[5]);
    else
        data->max_meals = -1;
    if (data->number_of_philos <= 0 || data->time_to_die <= 0 
        || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
        return (0);
    return (1);
}

static int  allocate_resources(t_data *data, t_philosophers **philos)
{
    int i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
    if (!data->forks)
        return (0);
    *philos = malloc(sizeof(t_philosophers) * data->number_of_philos);
    if (!*philos)
    {
        free(data->forks);
        return (0);
    }
    i = 0;
    while (i < data->number_of_philos)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
        {
            while (--i >= 0)
                pthread_mutex_destroy(&data->forks[i]);
            free(data->forks);
            free(*philos);
            return (0);
        }
        i++;
    }
    return (1);
}

int init_resources(t_data *data, t_philosophers **philos)
{
    int i;

    if (!allocate_resources(data, philos))
        return (0);
    if (pthread_mutex_init(&data->lock, NULL) != 0 ||
        pthread_mutex_init(&data->death_lock, NULL) != 0)
    {
        free_resources(data, *philos);
        return (0);
    }
    i = 0;
    while (i < data->number_of_philos)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].meal_eaten = 0;
        (*philos)[i].last_meal_eaten = 0;
        (*philos)[i].left_fork = &data->forks[i];
        (*philos)[i].rigth_fork = &data->forks[(i + 1) % data->number_of_philos];
        (*philos)[i].data = data;
        i++;
    }
    data->simulation_ended = 0;
    data->start_time = get_time();
    return (1);
}


