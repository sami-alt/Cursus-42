/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:39:40 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/16 13:22:35 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

int	main(int argc, char **argv)
{	
	if (argc > 1)
	{
		++argv;
		while (*argv)
		{
			ft_putstr(*argv);
			write(1, "\n", 1);
			argv++;
		}
	}
	return (0);
}
