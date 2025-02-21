/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 11:14:09 by sraiha            #+#    #+#             */
/*   Updated: 2025-01-30 11:14:09 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include "./Rank1/libft.h"
#include <signal.h>

void    send_bit(int pid, char c)
{
    int bit;

    bit = 8;
    while(bit--)
    {
        if ((c >> bit) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(500);
    }
}

int     main(int argc, char **argv)
{   
    int     pid;
    int     i;

    i = 0;
    while (argc == 3)
    {
        pid = ft_atoi(argc[1]);
        while(argv[2][i] != '\0')
                send_bit(pid, argv[2][i++]);
    }
    else {
        ft_print("Error");
        return (1);
    }

    return (0);
}