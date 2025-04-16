/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:01:01 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 13:19:34 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int ac, char **av)
{
    t_data data;
    t_philos *philos;
    
    philos = NULL;
    if (ac < 5 || ac > 6)
        return (printf("Usage: %s number_of_philso time_to_die time_to_eat time_to_sleep [number_of_meal]", av[0]), 1);
    if(!parse_arguments(ac, av, &data))
        return (printf("Error : invalid arguments"), 1);
    if(!init_resources(&data, &philos))
        clean_exit(&data, philos, 1);
    if (!launch_threads(&data, &philos))
        clean_exit(&data, philos, 1);
    clean_exit(&data, philos, 0);
    return (0);    
}