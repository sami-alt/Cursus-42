/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:30:10 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/19 17:13:45 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_input_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) == 0)
		return (0);
	return (1);
}

size_t	ft_count_fd(int fd)
{
	int		bytes_read;
	char	buffer[1];
	int		total_len;

	total_len = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, 1);
		total_len += bytes_read;
		if (bytes_read == 0)
			break ;
	}
	return (total_len);
}

int	main(int ac, char **ag)
{
	t_so_long	game_info;

	if (ac != 2)
		return (write(1, "Invalid argument count", 22), -1);
	game_info.length_argument = ft_strlen(ag[1]);
	if (game_info.length_argument < 5)
		return (write(1, "Error\nInvalid file", 18), 1);
	if (validate_input_file(ag[1]))
		return (write(1, "Error\nInvalid file", 18), 1);
	game_info.fd = open(ag[1], O_RDONLY);
	if (game_info.fd == -1)
		return (write(1, "Error\nInvalid file", 18), 1);
	game_info.map_raw_len = ft_count_fd(game_info.fd);
	game_info.map_raw = ft_calloc(sizeof(char), game_info.map_raw_len + 1);
	close(game_info.fd);
	game_info.fd = open(ag[1], O_RDONLY);
	read(game_info.fd, game_info.map_raw, game_info.map_raw_len);
	game_info.map = ft_split(game_info.map_raw, '\n');
	game_info.playable = ft_split(game_info.map_raw, '\n');
	game_info.map_error = 0;
	if (ft_error(&game_info) == 0)
		ft_run(&game_info);
	else
		ft_quit(&game_info);
	return (0);
}
