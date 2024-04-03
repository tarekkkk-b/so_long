/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:01:32 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/03 13:37:33 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == ESC)
		gameover(game);
	if (game->controls == 0)
		return (0);
	if (keycode == UP || keycode == W)
		move(game->map->x, game->map->y - 1, game);
	if (keycode == DOWN || keycode == S)
		move(game->map->x, game->map->y + 1, game);
	if (keycode == LEFT || keycode == A)
		move(game->map->x - 1, game->map->y, game);
	if (keycode == RIGHT || keycode == D)
		move(game->map->x + 1, game->map->y, game);
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
		mlx_put_image_to_window(game->mlx, game->window,
			game->tiles[2], game->map->x * TILE, game->map->y * TILE);
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[0], game->map->x * TILE, game->map->y * TILE);
		game->wasexit = 1;
	}
}

void	change_frames(int newx, int newy, t_game *game)
{
	game->map->x = newx;
	game->map->y = newy;
	game->map->map[newy][newx] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[2], game->map->x * TILE, game->map->y * TILE);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sonic[0], game->map->x * TILE, game->map->y * TILE);
}

void	move(int newx, int newy, t_game *game)
{
	if (game->map->map[newy][newx] == WALL)
		return ;
	ft_printf("Number of moves: %d\n", ++game->moves);
	if (game->map->map[newy][newx] == COIN)
		game->map->coins--;
	if (game->map->coins == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->exit[0],
			game->map->exitx * TILE, game->map->exity * TILE);
		game->exitflag = 1;
	}
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
