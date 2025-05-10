/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:12:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/10 11:46:29 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	while ((line = get_next_line(fd)) != NULL)
	{
		file[row] = ft_strdup(line);
		if (file[row] == NULL || row >= MAX_LINE)
		{
			free(line);
			free_file(file);
			return (NULL);
		}
		free(line);
		row++;
	}
	file[row] = NULL;
	close(fd);
	return (file);
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
		extract_color(game, game->file_content[i], &game->color.color_floor_r,&game->color.color_floor_g, &game->color.color_floor_b, "F");
		extract_color(game, game->file_content[i], &game->color.color_ceiling_r,&game->color.color_ceiling_g, &game->color.color_ceiling_b, "C");
		i++;
	}
	extract_map(game);
	check_map_char(game);
	check_param_order(game);
	
}
