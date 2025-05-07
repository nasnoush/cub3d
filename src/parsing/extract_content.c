/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:57:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/07 14:14:35 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	extract_texture(char *line, char **texture, char *name)
{
	int	i;

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

// void	extract_map(t_game *game)
// {
// 	int i;
// 	int size_map;
// 	int start;
// 	int start2;
// 	char **map;

// 	i = 0;
// 	start = 0;
// 	start2 = 0;
// 	size_map = 0;
// 	while (game->file_content[i])
// 	{
// 		if (game->file_content[i][0] == '1' && game->file_content[i][0])
// 		{
// 			while (game->file_content[i][0] != '\n')
// 				i--;
// 			i = i + 1;
// 			start = i;
// 			start2 = i;
// 			break ;
// 		}
// 		i++;
// 	}
// 	while (game->file_content[start])
// 	{
// 		start++;
// 		size_map++;
// 	}
// 	map = malloc(sizeof(char *) * (size_map + 1));
// 	if (map == NULL)
// 		return ;
// 	i = 0;
// 	while (game->file_content[start2])
// 	{
// 		map[i] = ft_strdup(game->file_content[start2]);
// 		i++;
// 		start2++;
// 	}

// 	map[i] = NULL;
// 	game->map = map;
// }

int	is_param_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i
			+ 1] == 'O') || (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'E' && line[i + 1] == 'A') || (line[i] == 'F' && (line[i
				+ 1] == ' ' || line[i + 1] == '\t')) || (line[i] == 'C'
			&& (line[i + 1] == ' ' || line[i + 1] == '\t')))
		return (1);
	return (0);
}

void	extract_map(t_game *game)
{
	int		i;
	int		start;
	int		size_map;
	char	**map;
	char	*temp;
	int		len;
	int		j;
	int		valid;

	i = 0;
	start = 0;
	size_map = 0;
	while (game->file_content[i])
	{
		if (!is_param_map(game->file_content[i])
			&& game->file_content[i][0] != '\n')
		{
			start = i;
			break ;
		}
		i++;
	}
	i = start;
	while (game->file_content[i])
	{
		j = 0;
		valid = 0;
		while (game->file_content[i][j])
		{
			if (game->file_content[i][j] != ' '
				&& game->file_content[i][j] != '\t'
				&& game->file_content[i][j] != '\n')
			{
				valid = 1;
				break ;
			}
			j++;
		}
		if (valid == 0)
			break ;
		size_map++;
		i++;
	}
	map = malloc(sizeof(char *) * (size_map + 1));
	if (map == NULL)
		return ;
	i = 0;
	while (i < size_map)
	{
		temp = ft_strdup(game->file_content[start + i]);
		len = ft_strlen(temp);
		if (len > 0 && temp[len - 1] == '\n')
			temp[len - 1] = '\0';
		map[i] = temp;
		i++;
	}
	map[i] = NULL;
	game->map = map;
}
