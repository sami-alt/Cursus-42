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
    t_philosophers *philosophers;
    
    philosophers = NULL;
    if (ac < 5 || ac > 6)
        return (printf("Usage: %s number_of_philso time_to_die time_to_eat time_to_sleep [number_of_meal]", av[0]), 1);
    if(!parse_arguments(av, av, &data))
        return (printf("Error : invalid arguments"), 1);
    if(!init_resources(&data, &philosophers))
        clean_exit(&data, philosophers, 1);
    if (!launc_threads(&data, &philosophers))
        clean_exit(&data, philosophers, 1);
    clean_exit(&data, philosophers, 0);
    return (0);    
}