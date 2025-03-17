/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 10:30:13 by sraiha            #+#    #+#             */
/*   Updated: 2025-02-13 10:30:13 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H_
#define SO_LONG_H_

# include "mlx.h"
# include "libft.h"

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
    void        *mlx_window;
    void        *img;
    void        *player;
    void        *wall;
    void        *floor;
    void        *collectible;
    void        *exit;
} so_long_t;


#endif