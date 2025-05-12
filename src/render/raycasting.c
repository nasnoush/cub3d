#include "../include/cub3d.h"

void algo_dda(t_game *game)
{
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
    	if (game->map[game->ray.map_y][game->ray.map_x] == '1')
        	game->ray.hit = 1;
	}
}

void draw_image(t_game *game, int x)
{
	t_img	*tex;
	int		y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x, tex_y;
	int		color;
	double	step;
	double	tex_pos;

	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x < 0)
			tex = &game->tiles.west;
		else
			tex = &game->tiles.east;
	}
	else 
	{
		if (game->ray.ray_dir_y < 0)
			tex = &game->tiles.north;
		else
			tex = &game->tiles.south;
	}
	line_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (game->ray.side == 0)
		wall_x = game->player.y + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->player.x + game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((game->ray.side == 0 && game->ray.ray_dir_x > 0) || 
		(game->ray.side == 1 && game->ray.ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	step = 1.0 * tex->height / line_height;
	tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		color = *(unsigned int *)(tex->img_data + (tex_y * tex->line_length + tex_x * (tex->bpp / 8)));
		*(unsigned int *)(game->img.img_data + (y * game->img.line_length + x * (game->img.bpp / 8))) = color;
		y++;
	}
}


void	raycasting(t_game *game)
{
	int		x;

	x = 0;
	while(x < WIDTH)
	{
		init_raycasting(game, x);
		algo_dda(game); //fonction a faire
		if (game->ray.side == 0)
			game->ray.perp_wall_dist = (game->ray.map_x - game->player.x + 
				(1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
		else
			game->ray.perp_wall_dist = (game->ray.map_y - game->player.y + 
				(1 - game->ray.step_y) / 2) / game->ray.ray_dir_y;

		draw_image(game, x); //fonction a faire
		x++;
	}
}