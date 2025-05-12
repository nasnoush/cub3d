/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_moove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:05:11 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/12 12:58:07 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int moove_up(t_game *game)
{
	game->player.x += game->player.dir_x * 0.1;
	game->player.y += game->player.dir_y * 0.1;
	return (0);
}

int moove_down(t_game *game)
{
	game->player.x -= game->player.dir_x * 0.1;
	game->player.y -= game->player.dir_y * 0.1;
	return (0);
}

int moove_left(t_game *game)
{
	game->player.x -= game->player.plane_x * 0.1;
	game->player.y -= game->player.plane_y * 0.1;
	return (0);
}

int moove_right(t_game *game)
{
	game->player.x += game->player.plane_x * 0.1;
	game->player.y += game->player.plane_y * 0.1;
	return (0);
}


int exit_escape(t_game *game)
{
	// mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.win_ptr);
	free_all(game);
	exit(0);
}

