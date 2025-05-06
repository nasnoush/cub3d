/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:47:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/06 12:11:50 by nadahman         ###   ########.fr       */
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
	
	game->file_content = load_file(av[1]);
	// load_map(av[1]);
	sort_pars(game);
	
	printf("NO texture : %s\n", game->text_no);
	printf("SO texture : %s\n", game->text_so);
	printf("WE texture : %s\n", game->text_we);
	printf("EA texture : %s\n", game->text_ea);
	printf("F, Couleur sol : r = %d g = %d b = %d\n", game->color.color_floor_r, game->color.color_floor_g, game->color.color_floor_b);
	printf("C, Couleur plafond : r = %d g = %d b = %d\n", game->color.color_ceiling_r, game->color.color_ceiling_g, game->color.color_ceiling_b);

	int i = 0;
	while (game->map[i])
	{
		printf("%s", game->map[i]);
		i++;
	}
	


	
	// pas oublier d initialiser la structure color
	return (0);
}


