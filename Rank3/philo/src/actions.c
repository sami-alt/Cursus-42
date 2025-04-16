/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:42:03 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 13:23:56 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *philosopher_routine(void *arg)
{
    t_philos *philosopher;
    
    philosopher = (t_philos *)arg;
    while(!stop_simulation(philosopher->data))
    {   
        take_forks(philosopher);
        eat(philosopher);
        drop_forks(philosopher);

        if (philosopher->data->max_meals == -1 && philosopher->meal_eaten >= philosopher->data->max_meals)
            break ;
        print_status(philosopher, "is sleeping");
        philo_sleep(philosopher->data->time_to_sleep);
        print_status(philosopher, "is thinking");
    }
    return (NULL);
}

int stop_simulation(t_data  *data)
{
    int     stop;
    pthread_mutex_lock(&data->death_lock);
    stop = data->simulation_ended;
    pthread_mutex_unlock(&data->death_lock);
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
    philosopher->meal_eaten++;
    print_status(philosopher, "is eating");
    philo_sleep(philosopher->data->time_to_eat);
}

void    drop_forks(t_philos *philosopher)
{
    pthread_mutex_unlock(philosopher->left_fork);
    pthread_mutex_unlock(philosopher->rigth_fork);
}