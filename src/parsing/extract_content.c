/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:57:42 by nadahman          #+#    #+#             */
/*   Updated: 2025/05/10 11:29:48 by nas              ###   ########.fr       */
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
		printf("Error : Texture non valide !\n");
		free_all(game);
		free(new_texture);
		exit(1);
	}
	if (*texture != NULL)
		free(*texture);
	*texture = new_texture;
}

int	recup_num(t_game *game, char *line, int *i)
{
	int	num = 0;

	if (line[*i] < '0' || line[*i] > '9')
	{
		printf("Error : Format de couleur non valide !\n");
		free_all(game);
		exit(1);
	}
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - '0');
		(*i)++;
	}
	if (num < 0 || num > 255)
	{
		printf("Error : Format de couleur non valide !\n");
		free_all(game);
		exit(1);
	}
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
	{
		printf("Error : Format de couleur non valide !\n");
		free_all(game);
		exit(1);
	}
	*g = recup_num(game, line, &i);
	if (line[i++] != ',')
	{
		printf("Error : Format de couleur non valide !\n");
		free_all(game);
		exit(1);
	}
	*b = recup_num(game, line, &i);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			printf("Error : Format de couleur non valide !\n");
			free_all(game);
			exit(1);
		}
		i++;
	}
}


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

int	is_map_line(char *line)
{
	int	i = 0;

	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != '\n' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	is_line_empty(char *line)
{
	int	i = 0;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	extract_map(t_game *game)
{
	int		i; 
	int start; 
	int size_map;
	char	**map;
	char *temp;
	int		len;
	i = 0;
	start = -1;
	size_map = 0;

	while (game->file_content[i])
	{
		if (is_map_line(game->file_content[i]) && !is_line_empty(game->file_content[i]))
		{
			start = i;
			break;
		}
		i++;
	}
	if (start == -1)
		return ;
	i = start;
	while (game->file_content[i])
	{
		if (!is_line_empty(game->file_content[i]) && is_map_line(game->file_content[i]))
			size_map++;
		else
			break;
		i++;
	}
	map = malloc(sizeof(char *) * (size_map + 1));
	if (!map)
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
	if (game->map == NULL || game->map[0] == NULL) 
	{
        printf("Error: La carte est vide.\n");
        free_all(game);
        exit(1);
    }
}

