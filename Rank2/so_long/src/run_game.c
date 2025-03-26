/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 4040/02/23 11:31:42 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/19 17:11:19 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_graphics(t_so_long *game)
{
	int	resolution;

	resolution = 40;
	game->player = mlx_xpm_file_to_image(game->mlx,
			"assets/xmp/knight2.xpm", &resolution, &resolution);
	if (!game->player)
		ft_quit(game);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"assets/xmp/wall2.xpm", &resolution, &resolution);
	if (!game->wall)
		ft_quit(game);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"assets/xmp/exit2.xpm", &resolution, &resolution);
	if (!game->exit)
		ft_quit(game);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/xmp/coin.xpm", &resolution, &resolution);
	if (!game->collectible)
		ft_quit(game);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"assets/xmp/empty2.xpm", &resolution, &resolution);
	if (!game->floor)
		ft_quit(game);
}

void	ft_run(t_so_long *game)
{
	int		width;
	int		height;

	width = game->width;
	height = game->height;
	game->step_count = 0;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, width * 40, height * 40,
			"-so-long-");
	game->img = mlx_new_image(game->mlx, height * 40, width * 40);
	ft_graphics(game);
	ft_draw_background(game);
	ft_draw_playable(game);
	mlx_loop_hook(game->mlx, ft_draw_player, game);
	mlx_key_hook(game->mlx_win, ft_key_hooks, game);
	mlx_hook(game->mlx_win, 17, 0, ft_quit, game);
	mlx_loop(game->mlx);
}
