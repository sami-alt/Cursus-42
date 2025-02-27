/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:30:13 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/27 15:09:04 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
    int         index;
    int         column;
    int         row;
    int         modified;

    int         fd;
    int         step_count;
    int         count_lenght_string;
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


int 	ft_key_hooks(int key_code, so_long_t *game_info);
void    ft_end_game(so_long_t *game_info);

#endif