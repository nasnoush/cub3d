/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:57:02 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/07 14:15:04 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int check_all_condition(t_game *game)
{
	if (check_is_valid(game) == 0)
		return (0);
		
	if (check_if_double(game) == 0)
		return (0);

	// check si la map est bien entouree de mur
	
	// check si la map est bien a la fin du fichier 
	
	return (1);
}

int check_if_double(t_game *game)
{
	int i;
	int j;
	int count;
	char **map;
	
	count = 0;
	i = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		printf("Error : Pas le bon nombre de joueur !\n");
		return (0);
	}
	return (1);
}


int check_is_valid(t_game *game)
{
	int i = 0;
	int j;
	char **map;

	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
			{
				printf("Error : Caractere invalide / manquant pour constituer la map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
