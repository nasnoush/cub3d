/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:12:54 by nadahman          #+#    #+#             */
/*   Updated: 2025/04/29 16:03:46 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char **load_map(char *file_name)
{
	int fd;
	char **map;
	char *line;
	int size_line;
	char *tmp;
	int row;
	
	size_line = MAX_LINE;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * MAX_LINE);  // ici mettre de quoi allouer la map
	if (map == NULL)
		return (NULL);
	row = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		
		map[row] = ft_strdup(line);
		if (row >= MAX_LINE && map[row] != NULL)
		{
			size_line = size_line * 2;
			
			tmp = realloc(line, size_line);
			if (tmp == NULL)
				return (NULL);
			
			line = tmp;
		}
		free(line);
		row++;
	}
	map[row] = NULL;
	close(fd);
	return (map);
}
