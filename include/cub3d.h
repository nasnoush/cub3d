/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:02:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/11 13:14:45 by nas              ###   ########.fr       */
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
	t_img	img;
	t_tiles tiles;
	
}t_game ;

// init
void	init_struct_color(t_game *game);

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
void	free_map(t_game *game);
void	free_file_content(t_game *game);
void	free_all(t_game *game);
void	free_file(char **file);

// assets
void	load_tiles(t_game *game, t_tiles *tiles, t_img *img);

// utils

int count_line(t_game *game);

#endif