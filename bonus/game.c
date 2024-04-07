/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:01:32 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:37:32 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == ESC)
		gameover(game);
	if (game->controls == 0)
		return (0);
	if (keycode == W)
		move(game->map->x, game->map->y - 1, game);
	if (keycode == S)
		move(game->map->x, game->map->y + 1, game);
	if (keycode == A)
	{
		move(game->map->x - 1, game->map->y, game);
		game->dir = LEFTDIR;
	}
	if (keycode == D)
	{
		move(game->map->x + 1, game->map->y, game);
		game->dir = RIGHTDIR;
	}
	else
		validatedash(keycode, game);
	return (0);
}

void	exittilehandling(t_game *game, int newx, int newy)
{
	if (game->exitflag == 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->tiles[2],
			game->map->x * TILE, game->map->y * TILE);
		game->map->map[game->map->y][game->map->x] = FLOOR;
		change_frames(newx, newy, game);
		game_won(game);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->window, game->tiles[2],
			game->map->x * TILE, game->map->y * TILE);
		game->map->map[game->map->y][game->map->x] = FLOOR;
		game->map->x = newx;
		game->map->y = newy;
		game->map->map[game->map->y][game->map->x] = PLAYER;
		mlx_put_image_to_window(game->mlx, game->window,
			game->tiles[2], game->map->x * TILE, game->map->y * TILE);
		game->wasexit = 1;
	}
}

void	change_frames(int newx, int newy, t_game *game)
{
	game->map->x = newx;
	game->map->y = newy;
	game->map->map[newy][newx] = PLAYER;
}

void	death(t_game *game)
{
	game->controls = 0;
	game->render = 0;
	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[2], game->map->x * TILE, game->map->y * TILE);
	if (game->map->map[game->map->y][game->map->x + 1] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->tiles[2], (game->map->x + 1) * TILE, game->map->y * TILE);
	if (game->map->map[game->map->y][game->map->x - 1] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->tiles[2], (game->map->x - 1) * TILE, game->map->y * TILE);
	if (game->map->map[game->map->y - 1][game->map->x] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->tiles[2], game->map->x * TILE, (game->map->y - 1) * TILE);
	if (game->map->map[game->map->y + 1][game->map->x] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->tiles[2], game->map->x * TILE, (game->map->y + 1) * TILE);
	if (game->dir == LEFTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[2], game->map->x * TILE, game->map->y * TILE);
	else if (game->dir == RIGHTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[3], game->map->x * TILE, game->map->y * TILE);
	game->death = 1;
	ft_printf("YOU DIED!\n");
}

void	move(int newx, int newy, t_game *game)
{
	game->idle = 0;
	if (game->map->map[newy][newx] == WALL)
		return ;
	if (game->map->map[newy][newx] == SPIKES
		|| game->map->map[newy][newx] == ENEMY)
		return (death(game));
	ft_printf("Number of moves: %d\n", ++game->moves);
	game->idle = 0;
	if (game->map->map[newy][newx] == COIN)
		game->map->coins--;
	mlx_put_image_to_window(game->mlx, game->window, game->tiles[2],
		game->map->x * TILE, game->map->y * TILE);
	if (game->map->map[newy][newx] == EXIT)
		return (exittilehandling(game, newx, newy));
	if (game->wasexit == 1)
	{
		game->map->map[game->map->y][game->map->x] = EXIT;
		game->wasexit = 0;
	}
	else
		game->map->map[game->map->y][game->map->x] = FLOOR;
	change_frames(newx, newy, game);
}
