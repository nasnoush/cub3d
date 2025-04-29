/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:14:29 by yann              #+#    #+#             */
/*   Updated: 2025/04/29 15:39:44 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../include/cub3d.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
// int		ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char *s1, const char *s2);
// void	*ft_calloc(unsigned int count, unsigned int size);

#endif