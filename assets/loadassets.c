/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadassets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:56:05 by nas               #+#    #+#             */
/*   Updated: 2025/05/05 14:04:31 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_tile_images(t_game *game, t_tiles *tiles, t_img *img)
{
	tiles->north = mlx_png_file_to_image(game->mlx, game->text_no, img->width,
			img->height);
	tiles->south = mlx_png_file_to_image(game->mlx, game->text_so, img->width,
		img->height);
	tiles->east = mlx_png_file_to_image(game->mlx, game->text_ea ,img->width,
		img->height);
	tiles->west = mlx_png_file_to_image(game->mlx, game->text_we ,img->width,
		img->height);
}