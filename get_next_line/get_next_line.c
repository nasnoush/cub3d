/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:14:23 by yann              #+#    #+#             */
/*   Updated: 2025/06/09 14:21:19 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ftg_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ftg_strdup(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_free_stock(char *stock)
{
	free(stock);
	stock = NULL;
	return (stock);
}

static char	*ft_extract_line(char **stock)
{
	char	*line;
	int		i;
	char	*temp;

	i = 0;
	if (*stock == NULL || **stock == '\0')
		return (NULL);
	while ((*stock)[i] != '\0' && (*stock)[i] != '\n')
		i++;
	line = (char *)malloc (i + 2);
	if (line == NULL)
		return (NULL);
	ftg_strlcpy(line, *stock, i + 2);
	if ((*stock)[i] == '\n')
		temp = ftg_strdup(*stock + i + 1);
	else
		temp = NULL;
	free(*stock);
	*stock = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_lu;
	char		*new_stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (stock = ft_free_stock(stock));
	bytes_lu = 1;
	while (bytes_lu > 0)
	{
		bytes_lu = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lu < 0)
			return (stock = ft_free_stock(stock));
		buffer[bytes_lu] = '\0';
		new_stock = ftg_strjoin(stock, buffer);
		stock = new_stock;
		if (found_line(stock) != -1)
			break ;
	}
	if (bytes_lu < 0 || (bytes_lu == 0 && (stock == NULL || *stock == '\0')))
		return (stock = ft_free_stock(stock));
	line = ft_extract_line(&stock);
	return (line);
}
