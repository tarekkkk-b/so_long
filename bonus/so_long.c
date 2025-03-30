/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:05:54 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:37:04 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	countenemies(t_parsemap **prsng)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*prsng)->map[i])
	{
		while ((*prsng)->map[i][j])
		{
			if ((*prsng)->map[i][j] == ENEMY)
			{
				(*prsng)->enemies++;
				(*prsng)->enemyy = i;
				(*prsng)->enemyx = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if ((*prsng)->enemies != 1)
	{
		write(2, "Wrong tokens count.\n", 20);
		(freeing((*prsng)->map, NULL, (*prsng)), exit(EF));
	}
}

void	attack(t_game *game, int newx, int newy)
{
	game->map->map[game->map->y][game->map->x] = FLOOR;
	game->map->map[newy][newx] = PLAYER;
	game->map->x = newx;
	game->map->y = newy;
	game->map->lastx = newx;
	game->map->lasty = newy;
	game->alive = 0;
}

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
	map->map->tempc = map->map->coins;
	countenemies(&map->map);
}

static void	game_initializer(t_game *game)
{
	game->dir = RIGHTDIR;
	game->enemydir = RIGHTDIR;
	game->tile = TILE;
	game->moves = 0;
	game->idle = 300;
	game->change = 0;
	game->newy = 0;
	game->newx = 0;
	game->move = 0;
	game->exitflag = 0;
	game->death = 0;
	game->controls = 1;
	game->end = 0;
	game->alive = 1;
	game->game = 1;
	game->render = 1;
	game->wasexit = 0;
	game->ringsframe = 0;
	game->speed = 0;
	game->exitcollected = 0;
	initialize_tiles(game);
	initialize_rings(game);
	initialize_dash(game);
	initialize_sonic(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		(write(2, "Usage: ./so_long [map].ber\n", 28), exit(EF));
	checkimages(setlist());
	game.map = malloc (sizeof(t_parsemap));
	parse_map(av[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map->cols * TILE,
			game.map->rows * TILE, "so_long");
	game_initializer(&game);
	mlx_hook(game.window, 2, 1L << 0, handle_keys, &game);
	mlx_hook(game.window, 17, 0, gameover, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
