#include "philo.h"

static void clean_threads(t_philo *philos, int created_count)
{
    int i;

    i = 0;
    while (i < created_count)
        pthread_join(philos[i++].thread, NULL);
}

int launch_threads(t_data *data, t_philo **philos)
{
    pthread_t   monitor;
    int         i;
    int         ret;

    i = 0;
    while (i < data->num_philos)
    {
        ret = pthread_create(&(*philos)[i].thread, NULL, philo_routine, &(*philos)[i]);
        if (ret != 0)
            return (clean_threads(*philos, i), 0);
        i++;
    }
    ret = pthread_create(&monitor, NULL, monitor_routine, *philos);
    if (ret != 0)
        return (clean_threads(*philos, data->num_philos), 0);
    i = 0;
    while (i < data->num_philos)
        pthread_join((*philos)[i++].thread, NULL);
    pthread_join(monitor, NULL);
    return (1);
}