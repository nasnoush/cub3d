/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_moove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:05:11 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/14 10:00:13 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int moove_up(t_game *game)
{
	double old_y;
	double old_x;

	old_x = game->player.x;
	old_y = game->player.y;
	game->player.x += game->player.dir_x * 0.1;
	game->player.y += game->player.dir_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = old_x;
		game->player.y = old_y;
	}
	return (0);
}

int moove_down(t_game *game)
{
	double old_y;
	double old_x;

	old_x = game->player.x;
	old_y = game->player.y;
	game->player.x -= game->player.dir_x * 0.1;
	game->player.y -= game->player.dir_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = old_x;
		game->player.y = old_y;
	}
	return (0);
}

int moove_left(t_game *game)
{
	double old_y;
	double old_x;

	old_x = game->player.x;
	old_y = game->player.y;
	game->player.x -= game->player.plane_x * 0.1;
	game->player.y -= game->player.plane_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = old_x;
		game->player.y = old_y;
	}
	return (0);
}

int moove_right(t_game *game)
{
	double old_y;
	double old_x;

	old_x = game->player.x;
	old_y = game->player.y;
	game->player.x += game->player.plane_x * 0.1;
	game->player.y += game->player.plane_y * 0.1;
	if(can_moove(game, (int)game->player.x, (int)game->player.y) == 0)
	{
		game->player.x = old_x;
		game->player.y = old_y;
	}
	return (0);
}


int exit_escape(t_game *game)
{
	free_all(game);
	exit(0);
}

