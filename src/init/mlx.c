#include "cub3d.h"

void    init_mlx(t_mlx *mlx, t_img *img)
{
    mlx->mlx_ptr = mlx_init();
    if (!mlx->mlx_ptr)
        return ;

    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, img->width, img->height, "cub3D");
    if (!mlx->win_ptr)
        return ;

    img->img_ptr = mlx_new_image(mlx->mlx_ptr, img->width, img->height);
    if (!img->img_ptr)
        return ;

    img->img_data = mlx_get_data_addr(
        img->img_ptr,
        &img->bpp,
        &img->line_length,
        &img->endian
    );
}
