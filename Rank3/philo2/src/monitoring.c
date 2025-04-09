/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-07 08:54:30 by sraiha            #+#    #+#             */
/*   Updated: 2025-04-07 08:54:30 by sraiha           ###   ########fii       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    check_philosopher_death(t_philosophers *philosopher, t_data *data)
{
    long current_time;
    long time_since_meal;

    current_time = get_time();
    time_since_meal = current_time - philosopher->last_meal_eaten;
    if (time_since_meal > philosopher->data->time_to_die)
    {
        pthread_mutex_lock(&data->death_lock);
        data->simulation_ended = 1;
        pthread_mutex_unlock(&data->death_lock);
        print_status(philosopher, "died");
    }
}

int     check_meal_completion(t_data *data, t_philosophers *philosopher)
{
    int i;
    int all_full;

    i = 0;
    all_full =  1;
    while(i < data->number_of_philos)
    {
        if (philosopher[i].meal_eaten < data->max_meals)
            all_full = 0;
        i++;
    }
    return (all_full);
}

void    *monitor(void *arg)
{
    t_philosophers *philosophers;
    t_data *data;
    int all_full;
    int i;

    data =  &philosophers[0].data;
    philosophers  = (t_philosophers *)arg;
    i = 0;
    while (1)
    {
        check_philosopher_death(&philosophers[i], data);
        if (data->max_meals != -1)
        {
            all_full = check_meal_completion(data, philosophers);
            if (all_full)
                exit(0);
        }
        i = (i + 1) % data->number_of_philos;
        if ( i == 0)
            usleep(1000);
    }
    return (NULL);
}

