/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:46:36 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/12 13:39:51 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"


int keycode_mo(int keycode, t_game *game)
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

// void	uptade_moove(t_game *game, int new_x, int new_y)
// {
// 	char next_pos;
// 	int pos_x;
// 	int pos_y;
	
// 	if (pos_x % 1 != 0)
// 		pos_x = (int)(game->player.x + 1);
// 	else
// 		pos_x = (int)(game->player.x);
// 	if (pos_y % 1 != 0)
// 		pos_x = (int)(game->player.y + 1);
// 	else
// 		pos_y = (int)(game->player.y);
// 	next_pos = game->map[new_x][new_y];
// 	if (next_pos == '1')
// 		return ;
// 	if (next_pos == '0')
// 	{
// 		game->map[(int)game->player.x][(int)game->player.y] = '0';
// 		game->map[new_y][new_x] = 'N';
// 		game->player.x = new_x;
// 		game->player.y = new_y;
// 	}
// }