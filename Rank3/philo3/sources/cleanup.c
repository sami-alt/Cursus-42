#include "philo.h"

void    clean_exit(t_data *data, t_philo *philos, int exit_code)
{
    int i;

    if (philos)
    {
        i = 0;
        while (i < data->num_philos)
            pthread_mutex_destroy(&data->forks[i++]);
        free(data->forks);
        free(philos);
    }
    pthread_mutex_destroy(&data->write_lock);
    pthread_mutex_destroy(&data->death_lock);
    exit(exit_code);
}