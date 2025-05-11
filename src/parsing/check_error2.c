/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:13:31 by nas               #+#    #+#             */
/*   Updated: 2025/05/11 10:06:50 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_cote(char **map, int i, int j)
{
	if (i == 0 || !map[i - 1] || j >= ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
		return (0);
	if (!map[i + 1] || j >= ft_strlen(map[i + 1]) || map[i + 1][j] == ' ')
		return (0);
	if (j == 0 || map[i][j - 1] == ' ')
		return (0);
	if (map[i][j + 1] == '\0' || map[i][j + 1] == ' ')
		return (0);
	
	return (1);
}

int	check_tile(char **map, int i, int j)
{
	if (map[i][j] == '0' || is_player_pos(map[i][j]))
	{
		if (!check_cote(map, i, j))
		{
			printf("Error : La carte n'est pas entourée de murs !\n");
			return (0);
		}
	}
	else if (map[i][j] != '1' && map[i][j] != ' ')
	{
		printf("Error : Caractère invalide !\n");
		return (0);
	}
	return (1);
}

int	check_map_tiles(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_tile(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_wall(t_game *game)
{
	char	**map;

	map = game->map;
	if (!map || !map[0])
	{
		printf("Error : Carte vide\n");
		return (0);
	}
	if (count_line(game) < 3)
	{
		printf("Error : Carte invalide !\n");
		return (0);
	}
	if (!check_map_tiles(map))
		return (0);
	return (1);
}






