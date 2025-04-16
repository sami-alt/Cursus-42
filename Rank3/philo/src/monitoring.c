/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:54:30 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 13:29:45 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int    check_philosopher_death(t_philos *philosopher, t_data *data)
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
        return (1);
    }
    return (0);
}

int     check_meal_completion(t_data *data, t_philos *philosopher)
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

void    *monitor_routine(void *arg)
{
    t_philos *philos;
    t_data *data;
    int     i;

    philos = (t_philos *)arg;
    data = philos[0].data;
    i = 0;
    while(1)
    {
        if (check_philosopher_death(&philos[i], data))
            return (NULL);
        i = (i + 1) %data->number_of_philos;
        if (i == 0 && usleep(1000) == -1)
            return (NULL);
    } 
}