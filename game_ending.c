#include "so_long.h"

void	destroysprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->coins[0]);
	mlx_destroy_image(game->mlx, game->exit[0]);
	mlx_destroy_image(game->mlx, game->sonic[0]);
	mlx_destroy_image(game->mlx, game->tiles[0]);
	mlx_destroy_image(game->mlx, game->tiles[1]);
	mlx_destroy_image(game->mlx, game->tiles[2]);
}

int	gameover(t_game *game)
{
	freeing(game->map->map, NULL, game->map);
	destroysprites(game);
	mlx_destroy_window(game->mlx, game->window);
	exit(S);
}

void	game_won(t_game *game)
{
	ft_printf("YOU WON\n");
	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[2], game->map->x * TILE, game->map->y * TILE);
	mlx_put_image_to_window(game->mlx, game->window,
		game->exit[0], game->map->x * TILE, game->map->y * TILE);
	game->controls = 0;
	game->exitcollected = 1;
}

int	checkexit(t_game *game)
{
	if (game->exitcollected == 1)
	{
		usleep(800000);
		gameover(game);
	}
	return (0);
}
