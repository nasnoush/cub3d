/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadassets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:56:05 by nas               #+#    #+#             */
/*   Updated: 2025/05/09 15:32:01 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_tile_images(t_game *game)
{
	game->tiles.north.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
	game->text_no, &game->tiles.north.width, &game->tiles.north.height);
	game->tiles.south.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
	game->text_so, &game->tiles.north.width, &game->tiles.north.height);
	game->tiles.west.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
	game->text_we, &game->tiles.north.width, &game->tiles.north.height);
	game->tiles.east.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
	game->text_ea, &game->tiles.north.width, &game->tiles.north.height);
}