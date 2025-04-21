
#include "philo.h"

static bool should_stop(t_philo *philo)
{
    bool    stop;

    pthread_mutex_lock(&philo->data->death_lock);
    stop = philo->data->simulation_ended;
    pthread_mutex_unlock(&philo->data->death_lock);
    return (stop);
}

void    take_forks(t_philo *philo)
{
    if (philo->id % 2 == 1)
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
    }
}

void    eat(t_philo *philo)
{
    philo->last_meal_time = get_time();
    print_status(philo, "is eating");
    custom_sleep(philo->data->time_to_eat);
    philo->meals_eaten++;
}

void    drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void    *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!should_stop(philo))
    {
        take_forks(philo);
        eat(philo);
        drop_forks(philo);
        if (philo->data->max_meals != -1 && 
            philo->meals_eaten >= philo->data->max_meals)
            break ;
        print_status(philo, "is sleeping");
        custom_sleep(philo->data->time_to_sleep);
        print_status(philo, "is thinking");
    }
    return (NULL);
}