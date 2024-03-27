/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarekkkk <tarekkkk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:05:54 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/27 23:04:00 by tarekkkk         ###   ########.fr       */
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
		(freeing(map->map->map, map->map->copy, map->map), exit(F));
	}
	validate_path(map->map->copy, map->map->x, map->map->y, &map->map);
	if (map->map->tempe != 0 || map->map->tempe != 0)
	{
		write(2, "No valid path found.\n", 21);
		(freeing(map->map->map, map->map->copy, map->map), exit(F));
	}
	freeing(NULL, map->map->copy, NULL);
}

static void	initialize_tiles(t_game *game)
{
	game->tile = TILE;
	game->tiles[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/xpm/border.xpm", &game->tile, &game->tile);
	game->tiles[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/xpm/wall.xpm", &game->tile, &game->tile);
	game->tiles[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/xpm/floor.xpm", &game->tile, &game->tile);
	game->coins[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/xpm/ring.xpm", &game->tile, &game->tile);
	game->sonic[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/xpm/sonic_left.xpm", &game->tile, &game->tile);
}

static void	renderborders(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map->map[++i])
	{
		while (game->map->map[i][++j])
		{
			if ((i == 0 || i == game->map->rows - 1)
				|| (j == 0 || j == game->map->cols -1))
					mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[0],	j * TILE, i * TILE);	
		}
		j = -1;
	}
}
static void	renderelements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map->map[++i])
	{
		while (game->map->map[i][++j])
		{
			if (game->map->map[i][j] == COIN)
				mlx_put_image_to_window(game->mlx, game->window,
					game->coins[0],	j * TILE, i * TILE);	
			if (game->map->map[i][j] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window,
					game->sonic[0],	j * TILE, i * TILE);	
			if (game->map->map[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window,
					game->coins[0],	j * TILE, i * TILE);	
		}
		j = -1;
	}
}

static void	rendermap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	initialize_tiles(game);
	renderborders(game);
	while (++i < game->map->rows - 1)
	{
		while (++j < game->map->cols - 1)
		{	
			if (game->map->map[i][j] == WALL)
					mlx_put_image_to_window(game->mlx, game->window,
						game->tiles[1],	j * TILE, i * TILE);
			if (game->map->map[i][j] != WALL)
					mlx_put_image_to_window(game->mlx, game->window,
							game->tiles[2],	j * TILE, i * TILE);
		}
		j = 0;
	}
	renderelements(game);
}

static void	move(int newx, int newy, t_game *game)
{
	if (game->map->map[newy][newx] == WALL)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, game->tiles[2],
			game->map->x * TILE, game->map->y * TILE);
	game->map->map[game->map->y][game->map->x] = FLOOR;
	game->map->x = newx;
	game->map->y = newy;
	game->map->map[newy][newx] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[2],	game->map->x * TILE, game->map->y * TILE);
	mlx_put_image_to_window(game->mlx, game->window,
					game->sonic[0],	game->map->x * TILE, game->map->y * TILE);
	usleep(100000);
}

static int	handle_keys(int keycode, t_game *game)
{
	if (keycode == UP)
		move(game->map->x, game->map->y - 1, game);
	if (keycode == DOWN)
		move(game->map->x, game->map->y + 1, game);
	if (keycode == LEFT)
		move(game->map->x - 1, game->map->y, game);
	if (keycode == RIGHT)
		move(game->map->x + 1, game->map->y, game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.map = malloc (sizeof(t_parsemap));
	if (ac != 2)
		(write(2, "Usage: ./so_long [map].ber\n", 28), exit (F));
	parse_map(av[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map->cols * TILE,
			game.map->rows * TILE, "so_long");
	rendermap(&game);
	mlx_hook(game.window, 2, 0, handle_keys, &game);
	mlx_loop(game.mlx);
	return (0);
}
