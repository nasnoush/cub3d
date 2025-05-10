/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:13:31 by nas               #+#    #+#             */
/*   Updated: 2025/05/10 10:35:05 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_valid_tile(char c)
{
	if (c == '0' || c == '1' || is_player_pos(c))
		return (1);
	return (0);
}

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

int	check_wall(t_game *game)
{
	int		i;
	int		j;
	char	**map;
	int		valid;
	
	map = game->map;
	valid = 1;
	if (!map || !map[0])
	{
		printf("Error : Carte vide\n");
		return (0);
	}
	else if (count_line(game) < 3)
	{
		printf("Error : Carte invalide !\n");
		return (0);
	}
	i = 0;
	while (map[i] && valid)
	{
		j = 0;
		while (map[i][j] && valid)
		{
			if (map[i][j] == '0' || is_player_pos(map[i][j]))
			{
				if (!check_cote(map, i, j))
				{
					printf("Error : La carte n'est pas entourée de murs !\n");
					valid = 0;
				}
			}
			else if (map[i][j] != '1' && map[i][j] != ' ')
			{
				printf("Error : Caractère invalide !\n");
				valid = 0;
			}
			j++;
		}
		i++;
	}
	return (valid);
}






