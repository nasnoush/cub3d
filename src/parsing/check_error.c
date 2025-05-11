/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:57:02 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/11 13:14:52 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int check_all_condition(t_game *game)
{
	if (check_wall(game) == 0)
		return (0);
	if (check_is_valid(game) == 0)
		return (0);
	if (check_if_double(game) == 0)
		return (0);
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


void check_param_order(t_game *game)
{
	int i;
	char **file;
	int count;

	file = game->file_content;
	i = 0;
	count = 0;

	while (file[i])
	{
		if (is_param_map(file[i]))
			count++;
		else if (file[i][0] != '\n' && file[i][0] != '\n')
			break ;
		i++;
	}
	if (count != 6)
		print_free_exit(game, "Error : Probleme dans les parametres de jeu !");
}

void	check_map_char(t_game *game)
{
	int i;
	int j;
	char **map;

	map = game->map;
	if (!map) 
        print_free_exit(game, "Error : Carte invalide !");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'S' && map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != ' ')
				print_free_exit(game, "Error : Caractere invalide dans la map !");
			j++;
		}
		i++;
	}
}
