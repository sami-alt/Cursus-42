#include "philo.h"

static bool check_philo_death(t_philo *philo, t_data *data)
{
    long    current_time;
    long    time_since_meal;

    current_time = get_time();
    time_since_meal = current_time - philo->last_meal_time;
    if (time_since_meal > data->time_to_die)
    {
        pthread_mutex_lock(&data->death_lock);
        data->simulation_ended = true;
        pthread_mutex_unlock(&data->death_lock);
        print_status(philo, "died");
        return (true);
    }
    return (false);
}

void    *monitor_routine(void *arg)
{
    t_philo *philos;
    t_data  *data;
    int     i;

    philos = (t_philo *)arg;
    data = philos[0].data;
    i = 0;
    while (1)
    {
        if (check_philo_death(&philos[i], data))
            return (NULL);
        i = (i + 1) % data->num_philos;
        if (i == 0 && usleep(1000) == -1)
            return (NULL);
    }
}