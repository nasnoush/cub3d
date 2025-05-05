#include "cube3d.h"

void	load_tile_images(void *mlx, t_tiles *tiles, int *width, int *height)
{
	tiles->texture_nord = mlx_png_file_to_image(mlx, "./texture/texture_nord.xpm", width,
			height);
	tiles->texture_sud = mlx_png_file_to_image(mlx, "./texture/texture_sud.xpm", width,
			height);
	tiles->texture_est = mlx_png_file_to_image(mlx, "./texture/texture_est.xpm", width,
			height);
	tiles->texture_ouest = mlx_png_file_to_image(mlx, "./texture/texture_ouest.xpm", width,
			height);
	tiles->plafon = mlx_png_file_to_image(mlx, "./texture/plafon.xpm", width,
			height);
	tiles->sol = mlx_png_file_to_image(mlx, "./texture/sol.xpm", width,
			height);
}