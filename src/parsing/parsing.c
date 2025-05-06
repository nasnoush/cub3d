/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:12:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/06 14:02:22 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char **load_file(char *file_name)
{
	int fd;
	char **file;
	char *line;
	int row;
	
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = malloc(sizeof(char *) * MAX_LINE);
	if (file == NULL)
		return (NULL);
	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		
		file[row] = ft_strdup(line);
		if (row >= MAX_LINE)
			break ;
		free(line);
		row++;
	}
	file[row] = NULL;
	close(fd);
	return (file);
}

void extract_texture(char *line, char **texture, char *name)
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


void	extract_color(char *line, int *r, int *g, int *b, char *name)
{
	int	i;

	if (ft_strncmp(line, name, ft_strlen(name)) != 0)
		return ;
	i = ft_strlen(name);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	*r = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != ',')
		return ;
	i++;
	*g = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != ',')
		return ;
	i++;
	*b = ft_atoi(&line[i]);
}


void	extract_map(t_game *game)
{
	int i;
	int size_map;
	int start;
	int start2;
	char **map;

	i = 0;
	start = 0;
	start2 = 0;
	size_map = 0;
	while (game->file_content[i])
	{
		if (game->file_content[i][0] == '1' && game->file_content[i][0])
		{	
			while (game->file_content[i][0] != '\n')
				i--;
			i = i + 1;
			start = i;
			start2 = i;
			break ;	
		}
		i++;
	}
	while (game->file_content[start])
	{
		start++;
		size_map++;
	}	
	map = malloc(sizeof(char *) * (size_map + 1));
	if (map == NULL)
		return ;
	i = 0;
	while (game->file_content[start2])
	{
		map[i] = ft_strdup(game->file_content[start2]);
		i++;
		start2++;
	}
	map[i] = NULL;
	game->map = map;
}

void	sort_pars(t_game *game)
{
	int i;

	i = 0;

	while (game->file_content[i])
	{
		
		extract_texture(game->file_content[i], &game->text_no, "NO");
		extract_texture(game->file_content[i], &game->text_so, "SO");
		extract_texture(game->file_content[i], &game->text_we, "WE");
		extract_texture(game->file_content[i], &game->text_ea, "EA");
		extract_color(game->file_content[i], &game->color.color_floor_r, &game->color.color_floor_g, &game->color.color_floor_b , "F");
		extract_color(game->file_content[i], &game->color.color_ceiling_r, &game->color.color_ceiling_g, &game->color.color_ceiling_b , "C");
		i++;
	}
	extract_map(game);
}



