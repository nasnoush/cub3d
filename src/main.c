/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:47:20 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/05 10:50:18 by yaoberso         ###   ########.fr       */
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
	int		i;

	i = 0;
	if (ac != 2 || strcmp(&av[1][ft_strlen(av[1]) - 4], ".cub") != 0)
	{
		printf("Error : <map> .cub file is expected");
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (1);
	game->map = load_map(av[1]);
	init_mlx(&game->mlx, &game->img);
	while (game->map[i])
	{
		printf("%s", game->map[i]);
		i++;
	}
	return (0);
}


