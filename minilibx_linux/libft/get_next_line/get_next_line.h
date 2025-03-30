/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:46:04 by enoshahi          #+#    #+#             */
/*   Updated: 2024/11/09 17:23:29 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef unsigned char	t_usc;

char	*get_next_line(int fd);
void	get_the_difference(char *buffer, int cap);
char	*ft_joinstr(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);

#endif