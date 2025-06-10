/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:57:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/06/08 13:25:54 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	extract_texture(t_game *game, char *line, char **texture, char *name)
{
	int		i;
	char	*trimmed_path;
	char	*raw_path;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(&line[i], name, 2) != 0)
		return ;
	i += 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	raw_path = ft_strdup(&line[i]);
	if (!raw_path)
		print_free_exit(game, "Error : Malloc failed");
	trimmed_path = ft_strtrim(raw_path, " \t\n");
	free(raw_path);
	if (!trimmed_path || *trimmed_path == '\0')
	{
		free(trimmed_path);
		print_free_exit(game, "Error : Texture non valide !");
	}
	if (*texture)
		free(*texture);
	*texture = trimmed_path;
}

int	recup_num(t_game *game, char *line, int *i)
{
	int	num;

	num = 0;
	if (line[*i] < '0' || line[*i] > '9')
		print_free_exit(game, "Error : Format de couleur non valide !");
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - '0');
		(*i)++;
	}
	if (num < 0 || num > 255)
		print_free_exit(game, "Error : Format de couleur non valide !");
	return (num);
}

void	extract_color(t_game *game, char *line, t_rgb *rgb, char *name)
{
	int	i;

	i = 0;
	skip_spaces(line, &i);
	if (ft_strncmp(&line[i], name, ft_strlen(name)) != 0)
		return ;
	i += ft_strlen(name);
	skip_spaces(line, &i);
	rgb->r = recup_num(game, line, &i);
	skip_spaces(line, &i);
	if (line[i++] != ',')
		print_free_exit(game, "Error : Format de couleur non valide !");
	skip_spaces(line, &i);
	rgb->g = recup_num(game, line, &i);
	skip_spaces(line, &i);
	if (line[i++] != ',')
		print_free_exit(game, "Error : Format de couleur non valide !");
	skip_spaces(line, &i);
	rgb->b = recup_num(game, line, &i);
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	if (line[i])
		print_free_exit(game, "Error : Format de couleur non valide !");
}

void	extract_map(t_game *game)
{
	int		start;
	int		size;
	char	**map;

	start = start_index(game->file_content);
	if (start == -1)
		return ;
	size = count_map_line(game->file_content, start);
	map = fill_map(game->file_content, start, size);
	if (!map || !map[0])
		print_free_exit(game, "Error : La carte est vide !");
	game->map = map;
}
