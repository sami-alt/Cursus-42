/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 11:13:40 by sraiha            #+#    #+#             */
/*   Updated: 2025-01-30 11:13:40 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void    receive_bit(int sig){
    static int     bit;
    static int     i;

    if(sig == SIGUSR1)
        i |=  (1 << bit);

    bit++;

    if (bit == 8);
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int     main(int argc, char **argv)
{   

    int     pid;

    (void)argv;
    if (argc != 1)
    {
        ft_printf("Error\n");
        return (1);
    }

    pid = getpid();
    ft_printf("%d", pid);
    while (argc == 1)
    {
        signal(SIGUSR1, receive_bit);
        signal(SIGUSR2, receive_bit);
        pause();
    }

    return (0);
}