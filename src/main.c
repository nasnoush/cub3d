/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:47:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/13 10:57:47 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int main(int argc, char **argv)
// {
// 	char **map;
// 	if (argc != 2)
// 		return (1);
// 	if (checkmap(map) == 0)
// 	{
// 		free_all();
// 		return (1);
// 	}
// 	init_mlx();
// 	main_loop();
// }

// int main(int ac, char **av)
// {
// 	t_game	*game;
	
// 	if (ac != 2 || strcmp(&av[1][ft_strlen(av[1]) - 4], ".cub") != 0)
// 	{
// 		printf("Error : <map> .cub file is expected");
// 		return (1);
// 	}
// 	game = malloc(sizeof(t_game));
// 	if (game == NULL)
// 		return (1);
// 	ft_memset(game, 0, sizeof(t_game));
// 	init_struct_color(game);
// 	printf("%s", game->text_no);
// 	game->file_content = load_file(av[1]);
// 	printf("%s", game->text_no);
// 	sort_pars(game);
// 	printf("%s", game->text_no);
// 	if (check_all_condition(game) == 0)
// 	{
// 		exit_game(game);
// 	}
// 	printf("%s", game->text_no);
// 	init_mlx(game);
// 	printf("%s", game->text_no);
// 	init_player(game);
// 	printf("%s", game->text_no);
// 	load_tile_images(game);
// 	mlx_loop_hook(game->mlx.mlx_ptr, render, game);
// 	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, keycode_mo, game);
// 	mlx_hook(game->mlx.win_ptr, 17, 0, exit_game, game);
// 	mlx_loop(game->mlx.mlx_ptr);
// 	free_all(game);
// 	printf("NO texture : %s\n", game->text_no);
// 	printf("SO texture : %s\n", game->text_so);
// 	printf("WE texture : %s\n", game->text_we);
// 	printf("EA texture : %s\n", game->text_ea);
// 	printf("F, Couleur sol : r = %d g = %d b = %d\n", game->color.color_floor_r, game->color.color_floor_g, game->color.color_floor_b);
// 	printf("C, Couleur plafond : r = %d g = %d b = %d\n", game->color.color_ceiling_r, game->color.color_ceiling_g, game->color.color_ceiling_b);

// 	printf("-----------------\n");

// 	int i = 0;
// 	while (game->map[i])
// 	{
// 		printf("%s\n", game->map[i]);
// 		i++;
// 	}
// 	free_all(game);
// 	return (0);
// }

int	render(t_game *game)
{
	raycasting(game); // dessine toute la scène dans game->img
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->img.img_ptr, 0, 0);
	return (0);
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}


int main(int ac, char **av)
{
	t_game	*game;
	
	if (ac != 2 || strcmp(&av[1][ft_strlen(av[1]) - 4], ".cub") != 0)
	{
		printf("Error : <map> .cub file is expected");
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	init_struct_color(game);
	game->file_content = load_file(av[1]);
	sort_pars(game);
	if (check_all_condition(game) == 0)
	{
		exit_game(game);
	}
	init_mlx(game);
	init_player(game);
	load_tile_images(game);
	mlx_loop_hook(game->mlx.mlx_ptr, render, game);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, keycode_mo, game);
	mlx_hook(game->mlx.win_ptr, 6, (1L << 6), mouse_move, game);
	mlx_hook(game->mlx.win_ptr, 17, 0, exit_game, game);
	mlx_loop(game->mlx.mlx_ptr);
	
	free_all(game);
	return (0);
}

