/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas <nas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:14:29 by yann              #+#    #+#             */
/*   Updated: 2025/05/10 11:49:18 by nas              ###   ########.fr       */
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
int	found_line(char *str);
void	free_get_next_line(void);
int		ftg_strlen(const char *s);
char	*ftg_strchr(const char *s, int c);
char	*ftg_strjoin(char *s1, const char *s2);
void	*ftg_calloc(unsigned int count, unsigned int size);

#endif