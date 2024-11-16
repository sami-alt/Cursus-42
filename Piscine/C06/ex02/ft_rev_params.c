/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:30:50 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/16 13:23:42 by sraiha           ###   ########.fr       */
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
	int	i;

	i = 0;
	while (argc > ++i)
	{
		ft_putstr(argv[argc - i]);
		ft_putstr("\n");
	}
	return (0);
}
