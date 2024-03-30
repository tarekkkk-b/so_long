/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:07:27 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/30 14:09:55 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief gets how many rows we have, and parses for empty middle lines
/// @param path the name of the map file
/// @param prsng the struct that has all my utils for prsng
void	linecount(char *path, t_parsemap **prsng)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	(*prsng)->line = get_next_line(fd);
	if (!(*prsng)->line)
		(write(2, "Empty map.\n", 11), (void)close(fd), free(*prsng), exit(EF));
	while ((*prsng)->line)
	{
		i++;
		if ((*prsng)->line[0] == '\n')
			(*prsng)->emptyline = 1;
		if ((*prsng)->line[0] != '\n' && (*prsng)->emptyline == 1)
		{
			write(2, "Empty line found in the map.\n", 29);
			(free((*prsng)->line), (void)close(fd), free (*prsng), exit(EF));
		}
		else if ((*prsng)->line[0] != '\n')
			(*prsng)->rows = i;
		free ((*prsng)->line);
		(*prsng)->line = get_next_line(fd);
	}
	free ((*prsng)->line);
	close (fd);
}

/// @brief validates the size of the map and if its regular shape
/// @param prsng the struct that has all my utils for prsng
void	validate_size(t_parsemap **prsng)
{
	int	i;
	int	temp;

	(*prsng)->cols = ft_strlen((*prsng)->map[0]);
	if ((*prsng)->cols < 3 || (*prsng)->rows < 3
		|| (*prsng)->cols * (*prsng)->rows < 15)
	{
		write(2, "Map is too small.\n", 18);
		(freeing((*prsng)->map, (*prsng)->copy, (*prsng)), exit(EF));
	}
	if ((*prsng)->cols > 23 || (*prsng)->rows > 11)
	{
		write(2, "Map is too big.\n", 16);
		(freeing((*prsng)->map, (*prsng)->copy, (*prsng)), exit(EF));
	}
	i = 1;
	while ((*prsng)->map[i])
	{
		temp = ft_strlen((*prsng)->map[i++]);
		if (temp != (*prsng)->cols)
		{
			write(2, "Map is irregular.\n", 18);
			(freeing((*prsng)->map, (*prsng)->copy, (*prsng)), exit(EF));
		}
	}
}

/// @brief checks if the borders of the map are walls
/// @param prsng the struct that has all my utils
void	mapclosed(t_parsemap **prsng)
{
	int	i;

	i = 0;
	if (check_occurance((*prsng)->map[0], WALL) == -1
		|| check_occurance((*prsng)->map[(*prsng)->rows - 1], WALL) == -1)
	{
		write(2, "Map is not closed.\n", 19);
		(freeing((*prsng)->map, (*prsng)->copy, (*prsng)), exit(EF));
	}
	while (i < (*prsng)->rows)
	{
		if ((*prsng)->map[i][0] != WALL
			|| (*prsng)->map[i][(*prsng)->cols - 1] != WALL)
		{
			write(2, "Map is not closed.\n", 19);
			(freeing((*prsng)->map, (*prsng)->copy, (*prsng)), exit(EF));
		}
		i++;
	}
}

/// @brief gets the map, and a copy of the map
/// @param path the name of the map file
/// @param prsng the struct the has all my utils for prsng 
void	get_map(char *path, t_parsemap **prsng)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	linecount(path, prsng);
	(*prsng)->map = malloc(sizeof(char *) * ((*prsng)->rows + 1));
	if ((!(*prsng)->map))
		(write(2, "Couldn't create map.\n", 21), free(*prsng), exit(EF));
	(*prsng)->copy = malloc(sizeof(char *) * ((*prsng)->rows + 1));
	if (!(*prsng)->copy)
		(write(2, "Couldn't create map.\n", 21),
			freeing((*prsng)->map, NULL, (*prsng)), exit(EF));
	while (i < (*prsng)->rows)
	{
		(*prsng)->map[i] = ft_strtrim(get_next_line(fd), "\n");
		(*prsng)->copy[i] = ft_strdup((*prsng)->map[i]);
		i++;
	}
	(*prsng)->map[i] = NULL;
	(*prsng)->copy[i] = NULL;
	close (fd);
}

void	validate_elements(t_parsemap **prsng)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*prsng)->rows)
	{
		while (j < (*prsng)->cols)
		{
			validate_char(prsng, (*prsng)->map[i][j]);
			if ((*prsng)->map[i][j] == COIN)
				(*prsng)->coins++;
			if ((*prsng)->map[i][j] == EXIT)
				(*prsng)->exit++;
			if ((*prsng)->map[i][j] == PLAYER)
			{
				(*prsng)->player++;
				(*prsng)->x = j;
				(*prsng)->y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
