/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-05 12:01:01 by sraiha            #+#    #+#             */
/*   Updated: 2025-04-05 12:01:01 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int ac, char **av)
{
    t_data data;
    t_philosophers *philosphers;
    pthread_t monitor;
    int i;

    if (ac < 5 || ac > 6)
        return(printf("Usage: ./philo n_philos t_die t_eat t_sleep [max_meals]\n"), 1);
    if(!parse_arguments(ac, av, &data)) 
        return (printf("Invalid arguments\n"), 1);
    if(!init_resources(&data, &philosphers))
        return (printf("Initilixzation failure"), 1);
    pthread_create(monitor, NULL, monitor, NULL);
    i = -1;
    while(++i < data.number_of_philos)
        pthread_join(&data, philosphers);
    pthread_join(monitor, NULL);
    free_resources(&data, philosphers);
    return  (0);
}