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

int     init_resources(t_data *data, t_philosophers **philosophers)
{   
    int i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
    *philosophers = malloc(sizeof(t_philosophers) * data->number_of_philos);
    data->start_time = get_time();
    pthread_mutex_init(&data->lock, NULL);
    i = -1;
    while (++i < data->number_of_philos)
        pthread_mutex_init(&data->forks[i], NULL);
    i = -1;
    while(++i < data->number_of_philos)
    {
        (*philosophers)[i].id = i + 1;
        (*philosophers)[i].meal_eaten = 0;
        (*philosophers)[i].last_meal_eaten = data->start_time;
        (*philosophers)[i].left_fork = &data->forks[i];
        (*philosophers)[i].rigth_fork = &data->forks[(i + 1) % data->number_of_philos];
        (*philosophers)[i].data = data;
        pthread_create(&(*philosophers)[i].thread, NULL, philosopher_routine, &(*philosophers)[i]);
    }
    return (1);
}

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
