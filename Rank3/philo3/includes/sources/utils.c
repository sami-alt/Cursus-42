#include "philo.h"

long    get_time(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void    print_status(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->data->write_lock);
    printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, msg);
    pthread_mutex_unlock(&philo->data->write_lock);
}

void    custom_sleep(long milliseconds)
{
    long    start;

    start = get_time();
    while (get_time() - start < milliseconds)
        usleep(500);
}