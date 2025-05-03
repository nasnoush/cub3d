/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:47:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/02 11:52:45 by nas              ###   ########.fr       */
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
	
	game->map = load_map(av[1]);
	// load_map(av[1]);
	sort_pars(game);
	
	printf("NO texture : %s\n", game->text_no);
	printf("SO texture : %s\n", game->text_so);
	printf("WE texture : %s\n", game->text_we);
	printf("EA texture : %s\n", game->text_ea);
	printf("F, Couleur sol : %d\n", game->color_floor);
	printf("C, Couleur plafond : %d\n", game->color_ceiling);


	// int i = 0;
	// while (game->map[i])
	// {
	// 	printf("%s", game->map[i]);
	// 	i++;
	// }
	return (0);
}


