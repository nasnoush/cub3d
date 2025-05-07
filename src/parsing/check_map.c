/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:57:02 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/07 19:38:51 by nas              ###   ########.fr       */
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
	
	// check si la map est bien a la fin du fichier 
	
	return (1);
}

int first_and_last_line(char *line)
{
	int	i = 0;

	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int check_wall(t_game *game)
{
	int i;
	int j;
	char **map;
	
	map = game->map;
	if (!map || !map[0])
		return (0);	
	if (!first_and_last_line(map[0]))
	{	
		printf("Error : La map n'est pas entouré de mur\n");
		return (0);
	}
	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
		{	
			printf("Error : La map n'est pas entouré de mur\n");
			return (0);
		}
		while (map[i][j])
			j++;
		j--;
		while (j > 0 && map[i][j] == ' ')
			j--;
		if (map[i][j] != '1')
		{	
			printf("Error : La map n'est pas entouré de mur\n");
			return (0);
		}
		i++;
	}
	if (!first_and_last_line(map[i]))
	{	
		printf("Error : La map n'est pas entouré de mur\n");
		return (0);
	}
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
