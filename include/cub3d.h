/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:02:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/06 10:50:55 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define MAX_LINE 10000

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

typedef	struct s_color
{
	int color_floor_r;
	int color_floor_g;
	int color_floor_b;
	int color_ceiling_r; 
	int color_ceiling_g;
	int color_ceiling_b;
	
} t_color;

typedef struct s_game
{
	void	*mlx;
	char **file_content;
	
	char **map;
	char *text_no;
	char *text_so;
	char *text_we;
	char *text_ea;

	t_color	color;
	
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
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	void        *ceiling;
    void        *floor;
}				t_tiles;

char **load_file(char *file_name);
void	sort_pars(t_game *game);

#endif