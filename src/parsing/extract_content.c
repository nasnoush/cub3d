/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:57:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/11 13:00:21 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	extract_texture(t_game *game, char *line, char **texture, char *name)
{
	int	i;
	int len;
	char *new_texture;
	
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(&line[i], name, 2) != 0)
		return ;
	i = i + 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	len = ft_strlen(&line[i]);
	if (line[i + len - 1] == '\n')
		len--;
	new_texture = ft_substr(&line[i], 0, len);
	if (new_texture == NULL || *new_texture == '\0')
	{
		free(new_texture);
		print_free_exit(game, "Error : Texture non valide !");
	}
	if (*texture != NULL)
		free(*texture);
	*texture = new_texture;
}

int	recup_num(t_game *game, char *line, int *i)
{
	int	num = 0;

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

void	extract_color(t_game *game, char *line, int *r, int *g, int *b, char *name)
{
	int	i = 0;

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(&line[i], name, ft_strlen(name)) != 0)
		return ;
	i += ft_strlen(name);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	*r = recup_num(game, line, &i);
	if (line[i++] != ',')
		print_free_exit(game, "Error : Format de couleur non valide !");
	*g = recup_num(game, line, &i);
	if (line[i++] != ',')
		print_free_exit(game, "Error : Format de couleur non valide !");
	*b = recup_num(game, line, &i);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			print_free_exit(game, "Error : Format de couleur non valide !");
		i++;
	}
}

void extract_map(t_game *game)
{
	int start;
	int size;
	char **map;
	
	start = start_index(game->file_content);
	if (start == -1)
		return ;
	size = count_map_line(game->file_content, start);
	map = fill_map(game->file_content, start, size);
	if (!map || !map[0])
		print_free_exit(game, "Error : La carte est vide !");
	game->map = map;
}


