/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:42:03 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 14:24:17 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool stop_simulation(t_philos  *philos)
{
    bool     stop;

    pthread_mutex_lock(&philos->data->death_lock);
    stop = philos->data->simulation_ended;
    pthread_mutex_unlock(&philos->data->death_lock);
    return (stop);
}



void    take_forks(t_philos *philosopher)
{
    if (philosopher->id % 2 == 1)
    {
        pthread_mutex_lock(philosopher->left_fork);
        print_status(philosopher, "has taken a fork");
        pthread_mutex_lock(philosopher->rigth_fork);
        print_status(philosopher, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philosopher->rigth_fork);
        print_status(philosopher, "has taken a fork");
        pthread_mutex_lock(philosopher->left_fork);
        print_status(philosopher, "has taken a fork");
    }
}

void    eat(t_philos *philosopher)
{
    philosopher->last_meal_eaten = get_time();
    print_status(philosopher, "is eating");
    philo_sleep(philosopher->data->time_to_eat);
    philosopher->meal_eaten++;
}

void    drop_forks(t_philos *philosopher)
{
    pthread_mutex_unlock(philosopher->left_fork);
    pthread_mutex_unlock(philosopher->rigth_fork);
}

void    *philosopher_routine(void *arg)
{
    t_philos *philosopher;
    
    philosopher = (t_philos *)arg;
    while(!stop_simulation(philosopher))
    {   
        take_forks(philosopher);
        eat(philosopher);
        drop_forks(philosopher);
        if (philosopher->data->max_meals != -1 && philosopher->meal_eaten >= philosopher->data->max_meals)
            break ;
        print_status(philosopher, "is sleeping");
        philo_sleep(philosopher->data->time_to_sleep);
        print_status(philosopher, "is thinking");
    }
    return (NULL);
}