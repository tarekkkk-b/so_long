/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ending.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:01:26 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:37:39 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	gameover(t_game *game)
{
	freeing(game->map->map, NULL, game->map);
	destroysprites(game);
	mlx_destroy_window(game->mlx, game->window);
	exit(ES);
}

void	couldntfindimage(t_game *game)
{
	destroysprites(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	freeing(game->map->map, NULL, game->map);
	write (2, "Couldn't find image.\n", 21);
	exit(EF);
}

void	game_won(t_game *game)
{
	char	*str;

	ft_printf("YOU WON\n");
	mlx_string_put(game->mlx, game->window, 125, 90, 0xffffff, "MOVES: ");
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 180, 90, 0xffffff, str);
	free(str);
	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[2], game->map->x * TILE, game->map->y * TILE);
	if (game->dir == LEFTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[0], game->map->x * TILE, game->map->y * TILE);
	else if (game->dir == RIGHTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[1], game->map->x * TILE, game->map->y * TILE);
	game->controls = 0;
	game->exitcollected = 1;
	game->game = 0;
}

void	renderwinningscreen(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->supersonic[0],
		(game->map->cols / 2) * TILE - 160, (game->map->rows / 2) * TILE - 200);
	mlx_string_put(game->mlx, game->window,
		(game->map->cols / 2) * TILE - 30, (game->map->rows / 2)
		* TILE + 200, 0xffffff, "YOU WIN");
	if (game->end > 10)
		gameover(game);
}
