/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:12:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/15 12:34:04 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	process_line(char **file, char *line, int row)
{
	file[row] = ft_strdup(line);
	if (file[row] == NULL || row >= MAX_LINE)
	{
		free(line);
		free_file(file);
		return (0);
	}
	free(line);
	return (1);
}

char	**load_file(char *file_name)
{
	int		fd;
	char	**file;
	char	*line;
	int		row;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = malloc(sizeof(char *) * MAX_LINE);
	if (file == NULL)
		return (NULL);
	row = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_line(file, line, row))
			return (NULL);
		row++;
		line = get_next_line(fd);
	}
	file[row] = NULL;
	close(fd);
	return (file);
}

void	check_map_end(t_game *game)
{
	int		i;
	int		param;
	char	**file;

	file = game->file_content;
	i = 0;
	param = 0;
	while (file[i])
	{
		if (is_param_map(file[i]))
			param++;
		else if (param == 6 && (file[i][0] == '1' || file[i][0] == ' '))
			return ;
		else if (param == 6 && file[i][0] != '\n')
			print_free_exit(game, "Error : Problemes dans les par de jeu ");
		i++;
	}
	print_free_exit(game, "Error : Problemes dans les parametres de jeu ");
}

unsigned int	rgb_int(int r, int g, int b)
{
	unsigned int	rgb;

	rgb = r;
	rgb = (rgb << 8) | g;
	rgb = (rgb << 8) | b;
	return (rgb);
}

void	sort_pars(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_content[i])
	{
		extract_texture(game, game->file_content[i], &game->text_no, "NO");
		extract_texture(game, game->file_content[i], &game->text_so, "SO");
		extract_texture(game, game->file_content[i], &game->text_we, "WE");
		extract_texture(game, game->file_content[i], &game->text_ea, "EA");
		extract_color(game, game->file_content[i], &game->color.color_floor_r,
			&game->color.color_floor_g, &game->color.color_floor_b, "F");
		extract_color(game, game->file_content[i], &game->color.color_ceiling_r,
			&game->color.color_ceiling_g, &game->color.color_ceiling_b, "C");
		i++;
	}
	game->color.ceiling = rgb_int(game->color.color_ceiling_r,
			game->color.color_ceiling_g, game->color.color_ceiling_b);
	game->color.floor = rgb_int(game->color.color_floor_r,
			game->color.color_floor_g, game->color.color_floor_b);
	extract_map(game);
	check_map_end(game);
	check_map_char(game);
	check_param_order(game);
}
