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

void	check_textures_paths(t_game *game)
{
	if (!game->text_no || !game->text_so || !game->text_we || !game->text_ea)
	{
		printf("Erreur: Chemins de texture non initialisés\n");
		exit_game(game);
	}
}

void	load_single_texture(t_game *game, t_img *texture, char *path,
		char *direction)
{
	texture->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		printf("Erreur: Impossible de charger la texture %s: %s\n",
			direction, path);
		exit_game(game);
	}
	texture->img_data = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_length, &texture->endian);
	if (!texture->img_data)
	{
		printf("Erreur: Impossible d'obtenir les données de texture %s\n",
			direction);
		exit_game(game);
	}
}

void	load_tile_images(t_game *game)
{
	check_textures_paths(game);
	load_single_texture(game, &game->tiles.north, game->text_no, "Nord");
	load_single_texture(game, &game->tiles.south, game->text_so, "Sud");
	load_single_texture(game, &game->tiles.west, game->text_we, "Ouest");
	load_single_texture(game, &game->tiles.east, game->text_ea, "Est");
}
