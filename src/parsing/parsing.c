/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:12:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/03 10:03:36 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char **load_map(char *file_name)
{
	int fd;
	char **map;
	char *line;
	// int size_line;
	// char *tmp;
	int row;
	
	// size_line = MAX_LINE;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * MAX_LINE);  // ici mettre de quoi allouer la map
	if (map == NULL)
		return (NULL);
	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		
		map[row] = ft_strdup(line);
		if (row >= MAX_LINE)
			break ;
		free(line);
		row++;
	}
	map[row] = NULL;
	close(fd);
	return (map);
}


// void	sort_pars(t_game *game)
// {
// 	int i = 0;
// 	int j;
// 	int start = 0;
// 	int end = 0;
	
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			if (game->map[i][j] == 'N' && game->map[i][j + 1] == 'O')
// 			{
// 				j = j + 2;
// 				while (game->map[i][j] == ' ' || game->map[i][j] == '\t')
// 					j++;
// 				start = j;
// 				while (game->map[i][j] != ' ' && game->map[i][j] != '\t' && game->map[i][j] != '\n')
// 					j++;
// 				end = j;
// 				game->text_no = ft_substr(game->map[i], start, end - start);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }


static	void extract_texture(char *line, char **texture, char *name)
{
	int i;
	
	if (ft_strncmp(line, name, 2) == 0)
	{
		i = 2;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		*texture = ft_substr(line, i, ft_strlen(line) - i - 1);
	}
}

static	void extract_color(char *line, int *value, char *name)
{
	int i;
	
	if (*value != 0)
		return ;
	if (ft_strncmp(line, name, ft_strlen(name)) == 0)
	{
		i = ft_strlen(name);
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		*value = ft_atoi(&line[i]);

		// la faut je rajoute pour stocker chaque couleur dans un int different
	}
}



void	sort_pars(t_game *game)
{
	int i;

	i = 0;

	while (game->map[i])
	{
		
		extract_texture(game->map[i], &game->text_no, "NO");
		extract_texture(game->map[i], &game->text_so, "SO");
		extract_texture(game->map[i], &game->text_we, "WE");
		extract_texture(game->map[i], &game->text_ea, "EA");
		extract_color(game->map[i], &game->color_floor, "F");
		extract_color(game->map[i], &game->color_ceiling, "C");
		
		i++;
	}
}



