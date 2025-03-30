/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:05:54 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/03 13:41:34 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief goes through all stages of parsing
/// @param path the name of the map file
/// @return the map to the main
void	parse_map(char *path, t_game *map)
{
	initializer(&map->map);
	validate_file(path, &map->map);
	get_map(path, &map->map);
	validate_size(&map->map);
	mapclosed(&map->map);
	validate_elements(&map->map);
	if (map->map->player != 1 || map->map->exit != 1 || map->map->coins < 1)
	{
		write(2, "Wrong tokens count.\n", 20);
		(freeing(map->map->map, map->map->copy, map->map), exit(EF));
	}
	validate_path(map->map->copy, map->map->x, map->map->y, &map->map);
	if (map->map->tempe != 0 || map->map->tempe != 0)
	{
		write(2, "No valid path found.\n", 21);
		(freeing(map->map->map, map->map->copy, map->map), exit(EF));
	}
	freeing(NULL, map->map->copy, NULL);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.moves = 0;
	game.exitflag = 0;
	game.controls = 1;
	game.wasexit = 0;
	game.exitcollected = 0;
	checkimages(setlist());
	game.map = malloc (sizeof(t_parsemap));
	if (ac != 2)
		(write(2, "Usage: ./so_long [map].ber\n", 28), exit(EF));
	parse_map(av[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map->cols * TILE,
			game.map->rows * TILE, "so_long");
	rendermap(&game);
	mlx_hook(game.window, 2, 1L << 0, handle_keys, &game);
	mlx_hook(game.window, 17, 0, gameover, &game);
	mlx_loop_hook(game.mlx, checkexit, &game);
	mlx_loop(game.mlx);
	return (0);
}
