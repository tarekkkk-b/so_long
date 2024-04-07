/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_and_extras.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:56 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:37:45 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	randomizer(t_game *game)
{
	int	random;

	random = rand() % 4 + 1;
	if (random == 1)
		enemymove(game, game->map->enemyx, game->map->enemyy - 1);
	if (random == 2)
		enemymove(game, game->map->enemyx, game->map->enemyy + 1);
	if (random == 3)
		enemymove(game, game->map->enemyx - 1, game->map->enemyy);
	if (random == 4)
		enemymove(game, game->map->enemyx + 1, game->map->enemyy);
	random = 0;
}

void	enemymove(t_game *game, int newx, int newy)
{
	if (game->map->enemyx - newx == -1)
		game->enemydir = RIGHTDIR;
	else if (game->map->enemyx - newx == 1)
		game->enemydir = LEFTDIR;
	if (game->map->map[newy][newx] != WALL
		&& game->map->map[newy][newx] != COIN
		&& game->map->map[newy][newx] != SPIKES
		&& game->map->map[newy][newx] != EXIT)
	{
		if (game->map->map[newy][newx] == PLAYER)
			return (death(game));
		game->map->map[game->map->enemyy][game->map->enemyx] = FLOOR;
		game->map->map[newy][newx] = ENEMY;
		game->map->enemyy = newy;
		game->map->enemyx = newx;
	}
	else
		return ;
}

void	validatedash(int keycode, t_game *game)
{
	if (keycode == UP)
		if (game->map->map[game->map->y - 1][game->map->x] != EXIT
			|| (game->map->map[game->map->y - 1][game->map->x] == EXIT
				&& game->exitflag == 0))
			game->move = 5;
	if (keycode == DOWN)
		if (game->map->map[game->map->y + 1][game->map->x] != EXIT
			|| (game->map->map[game->map->y + 1][game->map->x] == EXIT
				&& game->exitflag == 0))
			game->move = 6;
	if (keycode == LEFT)
		if (game->map->map[game->map->y][game->map->x - 1] != EXIT
			|| (game->map->map[game->map->y][game->map->x - 1] == EXIT
				&& game->exitflag == 0))
			game->move = 7;
	if (keycode == RIGHT)
		if (game->map->map[game->map->y][game->map->x + 1] != EXIT
			|| (game->map->map[game->map->y][game->map->x + 1] == EXIT
				&& game->exitflag == 0))
			game->move = 8;
}

void	rendermetalsonic(t_game *game, int i, int j)
{
	if (game->enemydir == LEFTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy[0], j * TILE, i * TILE);
	else if (game->enemydir == RIGHTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy[1], j * TILE, i * TILE);
}

void	renderdedmetalsonic(t_game *game)
{
	if (game->enemydir == LEFTDIR && game->alive == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy[3], game->map->lastx * TILE, game->map->lasty * TILE);
	else if (game->enemydir == RIGHTDIR && game->alive == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy[2], game->map->lastx * TILE, game->map->lasty * TILE);
}
