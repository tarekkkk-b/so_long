/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:46:15 by enoshahi          #+#    #+#             */
/*   Updated: 2024/11/10 19:18:32 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_the_difference(char *buffer, int cap)
{
	int	j;

	j = 0;
	while (buffer[cap] != '\0')
	{
		if (buffer[cap] == '\n')
		{
			cap++;
			while (buffer[cap] != '\0')
			{
				buffer[j] = buffer[cap];
				cap++;
				j++;
			}
			buffer[j] = '\0';
			break ;
		}
		cap++;
	}
	if (j == 0)
		buffer[0] = '\0';
}

char	*free_buf(char **buffer, char *ret, int rettype)
{
	free (*buffer);
	*buffer = NULL;
	if (rettype == 0)
	{
		if (rettype <= 0)
			free (ret);
		return (NULL);
	}
	return (ret);
}

void	initialize(char **ret, int *cap, char **buffer, int *j)
{
	*cap = 0;
	*j = 0;
	*ret = ft_joinstr(*ret, *buffer);
	if (!ret)
		free(ret);
	get_the_difference(*buffer, *cap);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*ret;
	int			buf_len;
	int			cap;
	int			j;

	if (buffer == NULL)
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	ret = NULL;
	while (ft_strchr(ret, '\n') == NULL)
	{
		if (buffer[0] == '\0')
		{
			buf_len = read(fd, buffer, BUFFER_SIZE);
			if (buf_len < 0)
				return (free_buf(&buffer, ret, 0));
			if (buf_len == 0)
				return (free_buf(&buffer, ret, 1));
			buffer[buf_len] = '\0';
		}
		initialize(&ret, &cap, &buffer, &j);
	}
	return (ret);
}

// int main(void)
// {
// 	char *str;
// 	int fd;
// 	fd = open("text.txt", O_RDONLY);
// 	// ! IN THE CASE OF RETURNING POINTERS ALWAYSSS MAKE SURE TO FREE !!!!!!!
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// }
