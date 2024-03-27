/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:42:22 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/27 13:57:48 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief frees a 2D array
/// @param map takes a 2D array, usually will be the map
/// @param copy takes a 2D array, usually will be the copy
void	freeing(char **map, char **copy, t_parsemap *prsng)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
	if (copy)
	{
		i = -1;
		while (copy[++i])
			free(copy[i]);
		free(copy);
	}
	if (prsng)
		free (prsng);
}

/// @brief checks if the file name is valid and file is openable
/// @param path the name of the map file
void	validate_file(char *path, t_parsemap **prsng)
{
	int	fd;

	if (!path)
		(write(2, "Usage: ./so_long [map].ber\n", 27), free(*prsng), exit(F));
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
		(write(2, "Usage: ./so_long [map].ber\n", 27), free(*prsng), exit(F));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		(write (2, "Couldn't find file.\n", 20), free(*prsng), exit(F));
	close (fd);
}

/// @brief checks if the top and bottom of the map are closed
/// @param row a row of the map, will be the top abd bottom
/// @param c character we wanna make sure is there entirely
/// @return true or false
int	check_occurance(char *row, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(row);
	while (i < len)
	{
		if (row[i] != c)
			return (0);
		i++;
	}
	return (1);
}

/// @brief validates the character
/// @param prsng the struct that has all my utils for parsing
/// @param c the character
void	validate_char(t_parsemap **prsng, char c)
{
	if (c != WALL && c != FLOOR && c != COIN && c != PLAYER && c != EXIT)
	{
		write (2, "Invalid token found.\n", 21);
		(freeing((*prsng)->map, (*prsng)->copy,(*prsng)), exit(F));
	}
}

/// @brief sets certain values to the struct
/// @param prsng the struct that has all my utils for parsing
void	initializer(t_parsemap **prsng)
{
	(*prsng)->tempc = -1;
	(*prsng)->tempe = -1;
	(*prsng)->emptyline = -1;
	(*prsng)->coins = 0;
	(*prsng)->player = 0;
	(*prsng)->exit = 0;
	(*prsng)->x = 0;
	(*prsng)->y = 0;
}
