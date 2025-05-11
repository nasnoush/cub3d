/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:15:19 by nas               #+#    #+#             */
/*   Updated: 2025/05/11 12:50:56 by nas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_param_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line[i] || !line[i + 1])
		return (0);
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

int start_index(char **file)
{
	int i = 0;

	i = 0;
	while (file[i])
	{
		if (is_map_line(file[i]) && !is_line_empty(file[i]))
			return (i);
		i++;
	}
	return (-1);
}

int count_map_line(char **file, int start)
{
	int count;

	count = 0;
	while (file[start])
	{
		count++;
		start++;
	}
	return (count);
}

char **fill_map(char **file, int start, int size)
{
	char **map;
	char *tmp;
	int i;
	int len;

	map = malloc(sizeof(char *) * (size + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp = ft_strdup(file[start + i]);
		len = ft_strlen(tmp);
		if (len > 0 && tmp[len - 1] == '\n')
			tmp[len - 1] = '\0';
		map[i] = tmp;
		i++;
	}
	map[i] = NULL;
	return (map);
}
