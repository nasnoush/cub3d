/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:02:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/05 10:47:37 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define MAX_LINE 10

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

typedef struct s_game
{
	t_mlx   mlx;
    t_img   img;
    t_player    player;
	char **map;
}t_game ;

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_mlx;


typedef struct s_player
{
    double  x;
    double  y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
}   t_player;

typedef struct s_img
{
    void    *img_ptr;
    char    *img_data;
    int     width;
    int     height;
    int     bpp;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_tiles
{
	void		*tex_nord;
	void		*tex_nord;
	void		*tex_nord;
	void		*tex_nord;
	void        *plafon;
    void        *sol;
}				t_tiles;

char **load_map(char *file_name);
void    init_mlx(t_mlx *mlx, t_img *img);

#endif