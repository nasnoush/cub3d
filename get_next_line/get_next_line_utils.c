/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:14:03 by yann              #+#    #+#             */
/*   Updated: 2025/04/29 15:40:08 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

// char	*ft_strjoin(char *s1, const char *s2)
// {
// 	char	*str;
// 	int		len1;
// 	int		len2;
// 	int		i;
// 	int		j;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	str = malloc((len1 + len2 + 1) * sizeof(char));
// 	if (str == NULL)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	i = -1;
// 	while (s1[++i])
// 		str[i] = s1[i];
// 	j = 0;
// 	while (s2[j])
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	free(s1);
// 	return (str);
// }

// void	*ft_calloc(unsigned int count, unsigned int size)
// {
// 	void			*ptr;
// 	unsigned char	*p;
// 	unsigned int	total_size;
// 	unsigned int	i;

// 	total_size = count * size;
// 	ptr = malloc(total_size);
// 	if (ptr == NULL)
// 		return (NULL);
// 	p = (unsigned char *)ptr;
// 	i = 0;
// 	while (i < total_size)
// 	{
// 		p[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }
