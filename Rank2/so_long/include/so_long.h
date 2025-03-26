/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:30:13 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/19 16:32:56 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

# define WALL '1'
# define SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct so_long_s
{
	char	*map_raw;
	char	**map;
	char	**playable;
	int		collectible_count;
	int		player_count;
	int		exit_count;
	int		column;
	int		row;
	int		modified;
	int		map_error;

	int		fd;
	size_t	step_count;
	int		map_raw_len;
	int		length_argument;

	int		player_x;
	int		player_y;
	size_t	index;
	size_t	width;
	size_t	height;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
}			t_so_long;

int			ft_error(t_so_long *game_info);

int			ft_check_map_chars(char const *line);
int			ft_validate_player_collectibles_exit(t_so_long *game_info);
int			ft_check_shape(t_so_long *game_info);
int			ft_line_count(char **arr);
int			ft_wall_check(t_so_long *game_info);

int			validate_input_file(char *filename);
size_t		ft_count_fd(int fd);
int			ft_is_winnable(t_so_long *game_info);
void		mark_playable(t_so_long *game_info);
int			find_playable(t_so_long *game_info);
int			ft_player_location(t_so_long *game_info);
int			ft_draw_player(t_so_long *game_info);
int			ft_draw_playable(t_so_long *game_info);
void		ft_draw_background(t_so_long *game_info);
void		ft_free_game(t_so_long *game_info);
void		ft_move(t_so_long *game_info, int x, int y);
int			ft_key_hooks(int key_code, t_so_long *game_info);
int			ft_check_map_chars(char const *line);
int			ft_validate_player_collectibles_exit(t_so_long *game_info);
int			ft_check_shape(t_so_long *game_info);
int			ft_line_count(char **arr);
int			ft_wall_check(t_so_long *game_info);
void		ft_graphics(t_so_long *game_info);
void		ft_run(t_so_long *game_info);
int			ft_quit(t_so_long *game_info);

#endif