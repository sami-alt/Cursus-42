/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:30:10 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/27 15:13:41 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_input_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if(ft_strncmp(filename - len  + 4, ".ber" ,4) == 0);
		return (1);

	return (0);
}

int main(void)
{	
	so_long_t game_info;

	

	return (0);
}
