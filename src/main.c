/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:47:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/06/09 12:54:42 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	render(t_game *game)
{
	raycasting(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->img.img_ptr, 0, 0);
	return (0);
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}

int	main(int ac, char **av)
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
	game->file_content = load_file(game, av[1]);
	init_mlx(game);
	sort_pars(game);
	if (check_all_condition(game) == 0)
		exit_game(game);
	load_tile_images(game);
	init_player(game);
	mlx_loop_hook(game->mlx.mlx_ptr, render, game);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, keycode_mo, game);
	mlx_hook(game->mlx.win_ptr, 6, (1L << 6), mouse_move, game);
	mlx_hook(game->mlx.win_ptr, 17, 0, exit_game, game);
	mlx_loop(game->mlx.mlx_ptr);
	free_all(game);
	return (0);
}
