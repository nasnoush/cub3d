/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:46:36 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/15 13:38:50 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	can_moove(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		return (0);
	}
	return (1);
}

int	keycode_mo(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		moove_up(game);
	if (keycode == KEY_A)
		moove_left(game);
	if (keycode == KEY_S)
		moove_down(game);
	if (keycode == KEY_D)
		moove_right(game);
	if (keycode == KEY_ESC)
		exit_escape(game);
	if (keycode == LEFT)
		slide_left(game);
	if (keycode == RIGHT)
		slide_right(game);
	return (0);
}
