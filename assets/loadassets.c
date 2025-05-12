/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadassets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:56:05 by nas               #+#    #+#             */
/*   Updated: 2025/05/12 10:26:26 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	load_tile_images(t_game *game)
// {
// 	game->tiles.north.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
// 	game->text_no, &game->tiles.north.width, &game->tiles.north.height);
// 	game->tiles.south.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
// 	game->text_so, &game->tiles.north.width, &game->tiles.north.height);
// 	game->tiles.west.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
// 	game->text_we, &game->tiles.north.width, &game->tiles.north.height);
// 	game->tiles.east.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
// 	game->text_ea, &game->tiles.north.width, &game->tiles.north.height);
// }

void load_tile_images(t_game *game)
{
    if (!game->text_no || !game->text_so || !game->text_we || !game->text_ea)
    {
        printf("Erreur: Chemins de texture non initialisés\n");
        exit_game(game);
    }
    game->tiles.north.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        game->text_no, &game->tiles.north.width, &game->tiles.north.height);
    if (!game->tiles.north.img_ptr)
    {
        printf("Erreur: Impossible de charger la texture Nord: %s\n", game->text_no);
        exit_game(game);
    }
    game->tiles.north.img_data = mlx_get_data_addr(game->tiles.north.img_ptr,
        &game->tiles.north.bpp, &game->tiles.north.line_length, &game->tiles.north.endian);
    if (!game->tiles.north.img_data)
    {
        printf("Erreur: Impossible d'obtenir les données de texture Nord\n");
        exit_game(game);
    }
    game->tiles.south.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        game->text_so, &game->tiles.south.width, &game->tiles.south.height);
    if (!game->tiles.south.img_ptr)
    {
        printf("Erreur: Impossible de charger la texture Sud: %s\n", game->text_so);
        exit_game(game);
    }
    game->tiles.south.img_data = mlx_get_data_addr(game->tiles.south.img_ptr,
        &game->tiles.south.bpp, &game->tiles.south.line_length, &game->tiles.south.endian);
    if (!game->tiles.south.img_data)
    {
        printf("Erreur: Impossible d'obtenir les données de texture Sud\n");
        exit_game(game);
    }
    game->tiles.west.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        game->text_we, &game->tiles.west.width, &game->tiles.west.height);
    if (!game->tiles.west.img_ptr)
    {
        printf("Erreur: Impossible de charger la texture Ouest: %s\n", game->text_we);
        exit_game(game);
    }
    game->tiles.west.img_data = mlx_get_data_addr(game->tiles.west.img_ptr,
        &game->tiles.west.bpp, &game->tiles.west.line_length, &game->tiles.west.endian);
    if (!game->tiles.west.img_data)
    {
        printf("Erreur: Impossible d'obtenir les données de texture Ouest\n");
        exit_game(game);
    }
    game->tiles.east.img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        game->text_ea, &game->tiles.east.width, &game->tiles.east.height);
    if (!game->tiles.east.img_ptr)
    {
        printf("Erreur: Impossible de charger la texture Est: %s\n", game->text_ea);
        exit_game(game);
    }
    game->tiles.east.img_data = mlx_get_data_addr(game->tiles.east.img_ptr,
        &game->tiles.east.bpp, &game->tiles.east.line_length, &game->tiles.east.endian);
    if (!game->tiles.east.img_data)
    {
        printf("Erreur: Impossible d'obtenir les données de texture Est\n");
        exit_game(game);
    }
}