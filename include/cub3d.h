/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:02:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/12 10:52:33 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H

#define MAX_LINE 10000
#define WIDTH 1600
#define HEIGHT 1200
#define KEY_ESC 65307
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100

#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include "../get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>


typedef	struct s_color
{
	int color_floor_r;
	int color_floor_g;
	int color_floor_b;
	int color_ceiling_r; 
	int color_ceiling_g;
	int color_ceiling_b;
	
} t_color;

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
	t_img north;
	t_img south;
	t_img west;
	t_img east;
	t_img ceiling;
	t_img floor;
} t_tiles;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_game
{
	char **file_content;
	
	char **map;
	char *text_no;
	char *text_so;
	char *text_we;
	char *text_ea;

	t_color	color;
	t_mlx	mlx;
	t_img	img;
	t_player	player;
	t_tiles		tiles;
	t_ray		ray;
	
}t_game ;

// init

void	init_struct_color(t_game *game);
void init_raycasting(t_game *game, int x);
void init_player(t_game *game);
void init_mlx(t_game *game);

// parsing

char **load_file(char *file_name);
void	sort_pars(t_game *game);
void extract_texture(t_game *game, char *line, char **texture, char *name);
void	extract_color(t_game *game, char *line, int *r, int *g, int *b, char *name);
void	extract_map(t_game *game);
int check_all_condition(t_game *game);
int check_is_valid(t_game *game);
int check_if_double(t_game *game);
int check_wall(t_game *game);
int	is_param_map(char *line);
void check_param_order(t_game *game);
void	check_map_char(t_game *game);
int	is_player_pos(char c);
int	is_valid_tile(char c);
void	print_free_exit(t_game *game, char *str);
int	is_line_empty(char *line);
int	is_map_line(char *line);
int start_index(char **file);
int count_map_line(char **file, int start);
char **fill_map(char **file, int start, int size);



// free 
int	exit_game(t_game *game);
void	free_map(t_game *game);
void	free_file_content(t_game *game);
void	free_all(t_game *game);
void	free_file(char **file);

// assets
void	load_tile_images(t_game *game);

// utils

int count_line(t_game *game);

// raycasting
void raycasting(t_game *game);

#endif