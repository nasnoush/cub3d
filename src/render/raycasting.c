/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:46:47 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/15 13:43:59 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	algo_dda(t_game *game)
{
	game->ray.hit = 0;
	while (!game->ray.hit)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->ray.map_y < 0 || game->ray.map_x < 0
			|| !game->map[game->ray.map_y]
			|| game->map[game->ray.map_y][game->ray.map_x] == '\0')
		{
			game->ray.hit = 1;
			break ;
		}
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

void	draw_ceiling_floor(t_game *game, int x, int draw_start, int draw_end)
{
	int				y;
	unsigned int	ceiling_color;
	unsigned int	floor_color;

	ceiling_color = game->color.ceiling;
	floor_color = game->color.floor;
	y = 0;
	while (y < draw_start)
	{
		if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
			*(unsigned int *)(game->img.img_data + (y * game->img.line_length
						+ x * (game->img.bpp / 8))) = ceiling_color;
		y++;
	}
	y = draw_end;
	while (y < HEIGHT)
	{
		if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
			*(unsigned int *)(game->img.img_data + (y * game->img.line_length
						+ x * (game->img.bpp / 8))) = floor_color;
		y++;
	}
}

void	select_texture(t_game *game, t_img **tex)
{
	*tex = NULL;
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x < 0)
			*tex = &game->tiles.west;
		else
			*tex = &game->tiles.east;
	}
	else
	{
		if (game->ray.ray_dir_y < 0)
			*tex = &game->tiles.north;
		else
			*tex = &game->tiles.south;
	}
}

void	draw_image(t_game *game, int x)
{
	t_img	*tex;

	select_texture(game, &tex);
	if (!tex || !tex->img_ptr || !tex->img_data)
	{
		printf("Erreur: Texture invalide dans draw_image\n");
		return ;
	}
	calculate_draw_params(game);
	draw_ceiling_floor(game, x, game->draw_params.draw_start,
		game->draw_params.draw_end);
	draw_tex_line(game, tex, x);
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_raycasting(game, x);
		algo_dda(game);
		if (game->ray.side == 0)
			game->ray.perp_wall_dist = (game->ray.map_x - game->player.x + (1
						- game->ray.step_x) / 2) / game->ray.ray_dir_x;
		else
			game->ray.perp_wall_dist = (game->ray.map_y - game->player.y + (1
						- game->ray.step_y) / 2) / game->ray.ray_dir_y;
		draw_image(game, x);
		x++;
	}
}
