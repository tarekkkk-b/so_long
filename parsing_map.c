/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:07:27 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/23 14:50:08 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief goes through all stages of parsing
/// @param path the name of the map file
/// @return the map to the main
char	**parse_map(char *path)
{
	t_parsemap	*parsing;

	validate_file(path);
	get_map(path, &parsing);
	return (parsing->map);
}

/// @brief checks if the file name is valid and file is openable
/// @param path the name of the map file
void	validate_file(char *path)
{
	int	fd;

	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
	{
		write(2, "Usage: ./so_long [map].ber\n", 27);
		exit (EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		(write (2, "Couldn't open file.\n", 20), exit (EXIT_FAILURE));
	close (fd);
}

/// @brief gets the map, and a copy of the map
/// @param path the name of the map file
/// @param parsing the struct the has all my utils for parsing 
void	get_map(char *path, t_parsemap *parsing)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	linecount(path, &parsing);
	parsing->map = malloc(sizeof(char *) * (parsing->rows + 1));
	parsing->copy = malloc(sizeof(char *) * (parsing->rows + 1));
	while (i < parsing->rows)
	{
		parsing->map[i] = get_next_line(fd);
		parsing->map[i] = ft_strtrim(parsing->map[i], "\n");
		parsing->copy[i] = get_next_line(fd);
		parsing->copy[i] = ft_strtrim(parsing->copy[i], "\n");
		i++;
	}
	parsing->map[i] = NULL;
	parsing->copy[i] = NULL;
	close (fd);
}

void	linecount(char *path, t_parsemap *parsing)
{
	int	fd;
	int	i;

	i = 0;
	parsing->check = -1;
	parsing->emptyline = -1;
	fd = open(path, O_RDONLY);
	parsing->line = get_next_line(fd);
	while (parsing->line)
	{
		i++;
		if (parsing->line[0] == '\n')
			parsing->emptyline = 1;
		if (parsing->line[0] != '\n' && parsing->emptyline == 1)
		{
			write(2, "Empty line found in the middle of the map.\n", 43);
			return (free(parsing->line), (void)close(fd), exit(EXIT_FAILURE));
		}
		else if (parsing->line[0] != '\n')
			parsing->check = i;
		free (parsing->line);
		parsing->line = get_next_line(fd);
	}
	free (parsing->line);
	close (fd);
}
