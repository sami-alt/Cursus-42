/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:33:16 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/28 13:07:50 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     ft_check_map_chars(char const *line)
{
    int i;

    i = 0;
    if(!line)
        return (-1);
    if(line[0] == '\n')
        return(write(1, "Error\nEndfound", 14), 1);
    while(line && line[i] !='\0')
    {
        if(line[i] != WALL && line[i] != SPACE && line[i] != PLAYER && line[i] != EXIT && line[i] != COLLECTIBLE && line[i] != '\n')
        {
            write(2, "Error\nInvalid character\n", 25);
            return (1);
        }
        if(line[i] == '\n' && line[i + 1] == '\n')
            return (write(1, "Error\nToo many linefeeds\n", 26), 1);
        i++;
    }
    return (0);
}

int     ft_validate_player_collectibles_exit(so_long_t *game_info)
{
    game_info->collectible_count = 0;
    game_info->exit_count = 0;
    game_info->player_count = 0;
    game_info->index = 0;
    if (!game_info->map_raw)
        return (-1);
    while (game_info->map_raw[game_info->index] != '\0')
    {
        if(game_info->map_raw[game_info->index]  == COLLECTIBLE)
            game_info->collectible_count++;
        else if (game_info->map_raw[game_info->index] == EXIT)
            game_info->exit_count++;
        else if (game_info->map_raw[game_info->index] == PLAYER)
            game_info->player_count++;
        game_info->index++;
    }
    if(game_info->collectible_count < 1)
        return(write(2, "Error\nToo few collectibles\n", 28), 1);
    if(game_info->exit_count != 1)
        return (write(2, "Error\nInvalid exit count\n", 26), 1);
    if(game_info->player_count != 1)
        return (write(1, "Error\nInvalid player count\n", 28), 1);
    return (0);
}

int     ft_check_shape(so_long_t *game_info)
{
    game_info->width = ft_strlen(game_info->map[0]);
    game_info->index = 1;
    while(game_info->map[game_info->index] != NULL)
    {
        if(ft_strlen(game_info->map[game_info->index]) != game_info->width)
            return (write(2, "Error\nInvalid map length", 26), 1);
        game_info->index++;
    }   
    return (0);
}
int     ft_line_count(char **arr)
{
    int     rows;

    rows  = 0;
    while(arr[rows] != NULL)
        rows++;
    return (rows);
}

int     ft_wall_check(so_long_t *game_info)
{
    game_info->index = 0;
    game_info->height = ft_line_count(game_info->map);
    while(game_info->map[0][game_info->index] != '\0')
    {
        if(game_info->map[0][game_info->index] != WALL)
            return (write(2, "Error\nInvalid map - wall error\n", 33), 1);
    }
    game_info->index = 0;
    while(game_info->map[game_info->height - 1][game_info->index] != '\0')
    {
        if(game_info->map[game_info->height - 1][game_info->index] != WALL)
            return(write(2, "Error\nInvalid map - wall error\n", 33), 1);
    }
    game_info->index = 0;
    while(game_info->index < game_info->height)
    {
        if (game_info->map[game_info->index][0] != WALL)
            return(write(2, "Error\nInvalid map - wall error\n", 33), 1);
        if (game_info->map[game_info->index][game_info->width -1] != WALL)
            return(write(2, "Error\nInvalid map - wall error\n", 33), 1);
        game_info->index++;
    }
    return (0);
}

