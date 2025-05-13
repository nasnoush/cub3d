/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:14:54 by nas               #+#    #+#             */
/*   Updated: 2025/05/13 10:57:06 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int count_line(t_game *game)
{
	int i;
	char **map;
	
	map = game->map;
	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	destroy_image(t_game *game)
{
	if (game->tiles.north.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tiles.north.img_ptr);
	if (game->tiles.south.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tiles.south.img_ptr);
	if (game->tiles.east.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tiles.east.img_ptr);
	if (game->tiles.west.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tiles.west.img_ptr);
	if (game->tiles.floor.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tiles.floor.img_ptr);
	if (game->tiles.ceiling.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->tiles.ceiling.img_ptr);
}

void	destroy_all(t_game *game)
{
	destroy_image(game);
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx.mlx_ptr, game->img.img_ptr);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	if (game->mlx.mlx_ptr)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
}
