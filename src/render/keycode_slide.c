/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_slide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:10:21 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/15 13:38:39 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_view(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y
		* cos(rot_speed);
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y
		* cos(rot_speed);
}

int	slide_left(t_game *game)
{
	rotate_view(game, -0.025);
	return (0);
}

int	slide_right(t_game *game)
{
	rotate_view(game, 0.025);
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x = -1;

	if (last_x == -1)
		last_x = x;
	if (x < last_x)
		slide_left(game);
	else if (x > last_x)
		slide_right(game);
	last_x = x;
	(void)y;
	return (0);
}
