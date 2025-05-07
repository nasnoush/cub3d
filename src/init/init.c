/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:24 by nas               #+#    #+#             */
/*   Updated: 2025/05/07 19:13:56 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_struct_color(t_game *game)
{
	game->color.color_floor_r = -1;
	game->color.color_floor_g = -1;
	game->color.color_floor_b = -1;
	game->color.color_ceiling_r = -1;
	game->color.color_ceiling_g = -1;
	game->color.color_ceiling_b = -1;
}