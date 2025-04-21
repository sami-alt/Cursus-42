#include "philo.h"

int main(int ac, char **av)
{
    t_data  data;
    t_philo *philos;

    philos = NULL;
    if (ac < 5 || ac > 6)
        return (printf("Usage: %s n_philo t_die t_eat t_sleep [n_meals]\n", av[0]), 1);
    if (!parse_args(ac, av, &data))
        return (printf("Error: Invalid arguments\n"), 1);
    if (!init_resources(&data, &philos))
        clean_exit(&data, philos, 1);
    if (!launch_threads(&data, &philos))
        clean_exit(&data, philos, 1);
    clean_exit(&data, philos, 0);
    return (0);
}