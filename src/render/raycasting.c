#include "../include/cub3d.h"

void algo_dda(t_game *game)
{

}

void draw_image(t_game *game)
{
	
}

void	raycasting(t_game *game)
{
	int		x;

	x = 0;
	while(x < WIDTH)
	{
		init_raycasting(game, x);
		algo_dda(game); //fonction a faire
		draw_image(game); //fonction a faire
		x++;
	}
}