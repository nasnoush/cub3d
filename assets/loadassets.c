/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadassets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:56:05 by nas               #+#    #+#             */
/*   Updated: 2025/06/09 14:15:08 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_tile_images(t_game *game)
{
	if (!game->text_no || !game->text_so || !game->text_we || !game->text_ea)
		exit_game(game);
	game->tiles.north.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->text_no, &game->tiles.north.width, &game->tiles.north.height);
	game->tiles.north.img_data = mlx_get_data_addr(game->tiles.north.img_ptr,
			&game->tiles.north.bpp, &game->tiles.north.line_length,
			&game->tiles.north.endian);
	game->tiles.south.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->text_so, &game->tiles.south.width, &game->tiles.south.height);
	game->tiles.south.img_data = mlx_get_data_addr(game->tiles.south.img_ptr,
			&game->tiles.south.bpp, &game->tiles.south.line_length,
			&game->tiles.south.endian);
	game->tiles.west.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->text_we, &game->tiles.west.width, &game->tiles.west.height);
	game->tiles.west.img_data = mlx_get_data_addr(game->tiles.west.img_ptr,
			&game->tiles.west.bpp, &game->tiles.west.line_length,
			&game->tiles.west.endian);
	game->tiles.east.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->text_ea, &game->tiles.east.width, &game->tiles.east.height);
	game->tiles.east.img_data = mlx_get_data_addr(game->tiles.east.img_ptr,
			&game->tiles.east.bpp, &game->tiles.east.line_length,
			&game->tiles.east.endian);
}
