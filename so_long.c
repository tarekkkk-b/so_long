/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarekkkk <tarekkkk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:05:54 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/25 21:06:27 by tarekkkk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief goes through all stages of parsing
/// @param path the name of the map file
/// @return the map to the main
void	parse_map(char *path, t_parsemap *prsng)
{
	initializer(&prsng);
	validate_file(path);
	get_map(path, &prsng);
	validate_size(&prsng);
	mapclosed(&prsng);
	validate_elements(&prsng);
	if (prsng->player != 1 || prsng->exit != 1 || prsng->coins < 1)
	{
		write(2, "Wrong tokens count.\n", 20);
		(freeing(prsng->map, prsng->copy), exit(EXIT_FAILURE));
	}
	validate_path(prsng->copy, prsng->x, prsng->y, &prsng);
	if (prsng->exit != 0 || prsng->coins != 0)
	{
		write(2, "No valid path found.\n", 21);
		(freeing(prsng->map, prsng->copy), exit(EXIT_FAILURE));
	}
	freeing(NULL, prsng->copy);
}

int	main(int ac, char **av)
{
	t_parsemap	prsng;

	if (ac != 2)
		(write(2, "Usage: ./so_long [map].ber\n", 28), exit (EXIT_FAILURE));
	parse_map(av[1], &prsng);
	freeing(prsng.map, NULL);
	return (0);
}
