#include "so_long.h"

int	handle_keys(int keycode, t_game *game)
{
	if (keycode == ESC)
		gameover(game);
	if (game->controls == 0)
		return (0);
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
	ft_printf("Number of moves: %d\n", ++game->moves);
	if (game->map->map[newy][newx] == WALL)
		return ;
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
	usleep(100000);
}
