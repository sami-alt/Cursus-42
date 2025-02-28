/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:30:13 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/28 13:19:54 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <fcntl.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WALL '1'
# define SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct so_long_s
{   
    char        *map_raw;
    char        **map;
    char        **playable;
    int         collectible_count;
    int         player_count;
    int         exit_count;
    int         column;
    int         row;
    int         modified;

    int         fd;
    int         step_count;
    int         map_raw_len;
    int         length_argument;

    int             player_x;
    int             player_y;
    size_t      index;
    size_t      width;
    size_t      height;
    void     	*mlx;
    void        *mlx_win;
    void        *img;
    void        *player;
    void        *wall;
    void        *floor;
    void        *collectible;
    void        *exit;
} so_long_t;

int     ft_error(so_long_t *game_info);

int     ft_check_map_chars(char const *line);
int     ft_validate_player_collectibles_exit(so_long_t *game_info);
int     ft_check_shape(so_long_t *game_info);
int     ft_line_count(char **arr);
int     ft_wall_check(so_long_t *game_info);

int	validate_input_file(char *filename);
size_t		ft_count_fd(int fd);
int    ft_is_winniable(so_long_t *game_info);
void    mark_playable(so_long_t *game_info);
int     find_playable(so_long_t *game_info);
int     ft_player_location(so_long_t *game_info);
void	ft_draw_player(so_long_t *game_info);
void    ft_draw_playable(so_long_t *game_info);
void    ft_draw_background(so_long_t *game_info);
void    ft_quit(so_long_t *game_info);
void    ft_free_game(so_long_t *game_info);
void 	ft_move(so_long_t *game_info, int x, int y);
int 	ft_key_hooks(int key_code, so_long_t *game_info);
int     ft_check_map_chars(char const *line);
int     ft_validate_player_collectibles_exit(so_long_t *game_info);
int     ft_check_shape(so_long_t *game_info);
int     ft_line_count(char **arr);
int     ft_wall_check(so_long_t *game_info);
int    ft_draw_images(so_long_t *game_info);
void    ft_graphics(so_long_t *game_info);
void    ft_run(so_long_t *game_info);



#endif