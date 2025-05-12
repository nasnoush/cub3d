/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:46:36 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/12 10:57:40 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"


int keycode(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		moove_up(keycode, game);
	if (keycode == KEY_A)
		moove_left(keycode, game);
	if (keycode == KEY_S)
		moove_down(keycode, game);
	if (keycode == KEY_D)
		moove_right(keycode, game);
	if (keycode == KEY_ESC)
		exit_escape(keycode, game);
}

int moove_up(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		
}