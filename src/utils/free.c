/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:20:53 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/13 10:57:04 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_game *game)
{
	int i;
	
	i = 0;
	
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_file_content(t_game *game)
{
	int i;
	
	i = 0;
	if (!game->file_content)
		return ;
	while (game->file_content[i])
	{
		free(game->file_content[i]);
		i++;
	}
	free(game->file_content);
	game->file_content = NULL;
}

void	free_file(char **file)
{
	int	i;

	if (!file)
		return;
	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}

void	free_texture(t_game *game)
{
	if (game->text_ea)
		free(game->text_ea);
	if (game->text_so)
		free(game->text_so);
	if (game->text_we)
		free(game->text_we);
	if (game->text_no)
		free(game->text_no);
	game->text_ea = NULL;
	game->text_so = NULL;
	game->text_we = NULL;
	game->text_no = NULL;
}


void	free_all(t_game *game)
{
	if (!game)
		return;
	free_map(game);
	free_file_content(game);
	free_texture(game);
	destroy_all(game);
	free(game);
}