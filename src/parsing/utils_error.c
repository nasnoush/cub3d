/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:06:32 by nas               #+#    #+#             */
/*   Updated: 2025/05/13 10:26:15 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_valid_tile(char c)
{
	if (c == '0' || c == '1' || is_player_pos(c))
		return (1);
	return (0);
}

void	print_free_exit(t_game *game, char *str)
{
	if (str)
		printf("%s\n", str);
	free_all(game);
	exit(1);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
