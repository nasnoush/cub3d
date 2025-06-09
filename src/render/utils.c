/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:31:12 by yaoberso          #+#    #+#             */
/*   Updated: 2025/05/15 13:49:43 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_draw_params(t_game *game)
{
	game->draw_params.line_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	if (game->draw_params.line_height <= 0)
		game->draw_params.line_height = HEIGHT;
	game->draw_params.draw_start = -game->draw_params.line_height / 2 + HEIGHT
		/ 2;
	if (game->draw_params.draw_start < 0)
		game->draw_params.draw_start = 0;
	game->draw_params.draw_end = game->draw_params.line_height / 2 + HEIGHT / 2;
	if (game->draw_params.draw_end >= HEIGHT)
		game->draw_params.draw_end = HEIGHT - 1;
	if (game->ray.side == 0)
		game->draw_params.wall_x = game->player.y + game->ray.perp_wall_dist
			* game->ray.ray_dir_y;
	else
		game->draw_params.wall_x = game->player.x + game->ray.perp_wall_dist
			* game->ray.ray_dir_x;
	game->draw_params.wall_x -= floor(game->draw_params.wall_x);
}

void	draw_tex_line(t_game *game, t_img *tex, int x)
{
	int	tex_x;

	tex_x = (int)(game->draw_params.wall_x * tex->width);
	if (tex_x < 0 || tex_x >= tex->width)
		tex_x = 0;
	if ((game->ray.side == 0 && game->ray.ray_dir_x > 0) || (game->ray.side == 1
			&& game->ray.ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	game->draw_params.step = 1.0 * tex->height / game->draw_params.line_height;
	draw_tex_pixels(game, tex, x, tex_x);
}

void	draw_tex_pixels(t_game *game, t_img *tex, int x, int tex_x)
{
	int		y;
	int		tex_y;
	int		color;
	double	tex_pos;

	tex_pos = (game->draw_params.draw_start - HEIGHT / 2
			+ game->draw_params.line_height / 2) * game->draw_params.step;
	y = game->draw_params.draw_start;
	while (y < game->draw_params.draw_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		if (tex_y < 0 || tex_y >= tex->height)
			tex_y = 0;
		tex_pos += game->draw_params.step;
		if (tex->bpp / 8 * tex_x + tex_y * tex->line_length < tex->height
			* tex->line_length)
		{
			color = *(unsigned int *)(tex->img_data + (tex_y * tex->line_length
						+ tex_x * (tex->bpp / 8)));
			if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH)
				*(unsigned int *)(game->img.img_data + (y
							* game->img.line_length + x * (game->img.bpp
								/ 8))) = color;
		}
		y++;
	}
}
