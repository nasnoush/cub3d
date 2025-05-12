/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:09:24 by nas               #+#    #+#             */
/*   Updated: 2025/05/12 08:56:10 by yaoberso         ###   ########.fr       */
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

void    init_mlx(t_game *game)
{
	game->img.width = WIDTH;
    game->img.height = HEIGHT;
    game->mlx.mlx_ptr = mlx_init();
    if (!game->mlx.mlx_ptr)
        return ;

    game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, game->img.width, game->img.height, "cub3D");
    if (!game->mlx.win_ptr)
        return ;

    game->img.img_ptr = mlx_new_image(game->mlx.mlx_ptr, game->img.width, game->img.height);
    if (!game->img.img_ptr)
        return ;

    game->img.img_data = mlx_get_data_addr(
        game->img.img_ptr,
        &game->img.bpp,
        &game->img.line_length,
        &game->img.endian
    );
}

void init_player(t_game *game)
{
	char **map;
	int		y;
	int		x;

	x = 0;
	y = 0;
	map = game->map;
	while(map[x] != NULL)
	{
		y = 0;
		while(map[x][y] != '\0')
		{
			if (map[x][y] == 'N' || map[x][y] == 'S' || map[x][y] == 'E' || map[x][y] == 'W')
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
				if (map[x][y] == 'N')
				{
					game->player.dir_x = 0;
					game->player.dir_y = -1;
					game->player.plane_x = 0.66;
					game->player.plane_y = 0;
				}
				else if (map[x][y] == 'S')
				{
					game->player.dir_x = 0;
					game->player.dir_y = 1;
					game->player.plane_x = -0.66;
					game->player.plane_y = 0;
				}
				else if (map[x][y] == 'E')
				{
					game->player.dir_x = 1;
					game->player.dir_y = 0;
					game->player.plane_x = 0;
					game->player.plane_y = 0.66;
				}
				else if (map[x][y] == 'W')
				{
					game->player.dir_x = -1;
					game->player.dir_y = 0;
					game->player.plane_x = 0;
					game->player.plane_y = -0.66;
				}
				return;
			}
			y++;
		}
		x++;
	}
}

void init_raycasting(t_game *game, int x)
{
    game->ray.camera_x = 2 * x / (double)WIDTH - 1;
    game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x * game->ray.camera_x;
    game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y * game->ray.camera_x;
    game->ray.map_x = (int)game->player.x;
    game->ray.map_y = (int)game->player.y;
    game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
    game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	if (game->ray.ray_dir_x < 0)
	{
    	game->ray.step_x = -1;
    	game->ray.side_dist_x = (game->player.x - game->ray.map_x) * game->ray.delta_dist_x;
	}
	else
	{
    	game->ray.step_x = 1;
    	game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
    	game->ray.side_dist_y = (game->player.y - game->ray.map_y) * game->ray.delta_dist_y;
	}
	else
	{
    	game->ray.step_y = 1;
    	game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.y) * game->ray.delta_dist_y;
	}
}