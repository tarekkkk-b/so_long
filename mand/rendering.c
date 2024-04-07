/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:01:40 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 12:54:05 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_tiles(t_game *game)
{
	game->tile = TILE;
	game->tiles[0] = mlx_xpm_file_to_image(game->mlx,
			"./mand/textures/xpm/border.xpm", &game->tile, &game->tile);
	game->tiles[1] = mlx_xpm_file_to_image(game->mlx,
			"./mand/textures/xpm/wall.xpm", &game->tile, &game->tile);
	game->tiles[2] = mlx_xpm_file_to_image(game->mlx,
			"./mand/textures/xpm/floor.xpm", &game->tile, &game->tile);
	game->coins[0] = mlx_xpm_file_to_image(game->mlx,
			"./mand/textures/xpm/ring.xpm", &game->tile, &game->tile);
	game->sonic[0] = mlx_xpm_file_to_image(game->mlx,
			"./mand/textures/xpm/sonic.xpm", &game->tile, &game->tile);
	game->sonic[1] = mlx_xpm_file_to_image(game->mlx,
			"./mand/textures/xpm/sonicwin.xpm", &game->tile, &game->tile);
	game->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"./mand/textures/xpm/emerald.xpm", &game->tile, &game->tile);
}

void	rendermap(t_game *game)
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
					game->tiles[1], j * TILE, i * TILE);
			if (game->map->map[i][j] != WALL)
				mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[2], j * TILE, i * TILE);
		}
		j = 0;
	}
	renderelements(game);
}

void	renderborders(t_game *game)
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
					game->tiles[0], j * TILE, i * TILE);
		}
		j = -1;
	}
}

void	renderelements(t_game *game)
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
					game->coins[0], j * TILE, i * TILE);
			if (game->map->map[i][j] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window,
					game->sonic[0], j * TILE, i * TILE);
		}
		j = -1;
	}
}
