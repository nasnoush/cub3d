/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:14:23 by yann              #+#    #+#             */
/*   Updated: 2024/11/03 15:07:09 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (text == NULL)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_strjoin(text, buffer);
		if (ft_strchr(text, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (text);
}

static char	*get_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (text[i] == '\0')
		return (NULL);
	while ((text[i] != '\0') && (text[i] != '\n'))
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		str[i++] = '\n';
	return (str);
}

static char	*clean_first_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(text) - i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (text[i++] != '\0')
	{
		str[j] = text[i];
		j++;
	}
	str[j] = '\0';
	free(text);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_first_line(fd, text);
	if (text == NULL)
		return (NULL);
	output_text = get_line(text);
	text = clean_first_line(text);
	return (output_text);
}

/*#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/