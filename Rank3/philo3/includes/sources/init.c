#include "philo.h"

int parse_args(int ac, char **av, t_data *data)
{
    data->num_philos = atoi(av[1]);
    data->time_to_die = atoi(av[2]);
    data->time_to_eat = atoi(av[3]);
    data->time_to_sleep = atoi(av[4]);
    data->max_meals = (ac == 6) ? atoi(av[5]) : -1;
    if (data->num_philos <= 0 || data->time_to_die <= 0 || 
        data->time_to_eat <= 0 || data->time_to_sleep <= 0 ||
        (ac == 6 && data->max_meals <= 0))
        return (0);
    return (1);
}

static int  init_mutexes(t_data *data)
{
    int i;

    i = 0;
    while (i < data->num_philos)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            return (0);
        i++;
    }
    if (pthread_mutex_init(&data->write_lock, NULL) != 0 ||
        pthread_mutex_init(&data->death_lock, NULL) != 0)
        return (0);
    return (1);
}

int init_resources(t_data *data, t_philo **philos)
{
    int i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
    if (!data->forks)
        return (0);
    *philos = malloc(sizeof(t_philo) * data->num_philos);
    if (!*philos)
        return (free(data->forks), 0);
    if (!init_mutexes(data))
        return (free(data->forks), free(*philos), 0);
    i = 0;
    while (i < data->num_philos)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].meals_eaten = 0;
        (*philos)[i].last_meal_time = 0;
        (*philos)[i].left_fork = &data->forks[i];
        (*philos)[i].right_fork = &data->forks[(i + 1) % data->num_philos];
        (*philos)[i].data = data;
        i++;
    }
    data->simulation_ended = false;
    data->start_time = get_time();
    return (1);
}