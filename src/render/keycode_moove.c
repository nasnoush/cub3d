/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_moove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:05:11 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/13 12:29:01 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int moove_up(t_game *game)
{
	double hold_y;
	double hold_x;

	hold_x = game->player.x;
	hold_y = game->player.y;
	game->player.x += game->player.dir_x * 0.1;
	game->player.y += game->player.dir_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = hold_x;
		game->player.y = hold_y;
	}
	return (0);
}

int moove_down(t_game *game)
{
	double hold_y;
	double hold_x;

	hold_x = game->player.x;
	hold_y = game->player.y;
	game->player.x -= game->player.dir_x * 0.1;
	game->player.y -= game->player.dir_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = hold_x;
		game->player.y = hold_y;
	}
	return (0);
}

int moove_left(t_game *game)
{
	double hold_y;
	double hold_x;

	hold_x = game->player.x;
	hold_y = game->player.y;
	game->player.x -= game->player.plane_x * 0.1;
	game->player.y -= game->player.plane_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = hold_x;
		game->player.y = hold_y;
	}
	return (0);
}

int moove_right(t_game *game)
{
	double hold_y;
	double hold_x;

	hold_x = game->player.x;
	hold_y = game->player.y;
	game->player.x += game->player.plane_x * 0.1;
	game->player.y += game->player.plane_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = hold_x;
		game->player.y = hold_y;
	}
	return (0);
}


int exit_escape(t_game *game)
{
	// mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.win_ptr);
	free_all(game);
	exit(0);
}

