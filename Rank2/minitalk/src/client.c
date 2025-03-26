/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:14:09 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/17 15:07:44 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_received = 0;

void	handler(int sig)
{
	(void)sig;
	g_received = 1;
}

void	send_bit(char *str, int pid)
{
	int		bit;
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{	
		c = str[i];
		bit = 7;
		while (bit >= 0)
		{	
			g_received = 0;
			if ((c >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_received)
				pause();
			usleep(150);
			bit--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (write(1, "sigaction", 1), -1);
	if (argc != 3)
		return (write(1, "Invalid argument count\n", 23), 0);
	str = argv[2];
	pid = ft_atoi(argv[1]);
	send_bit(str, pid);
	return (0);
}
