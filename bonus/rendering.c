/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:01:40 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:37:12 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	rendertext(t_game *game)
{
	char	*str;

	mlx_string_put(game->mlx, game->window, 125, 90, 0xffffff, "MOVES: ");
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 180, 90, 0xffffff, str);
	free(str);
	mlx_string_put(game->mlx, game->window, 125, 115, 0xffffff, "RINGS: ");
	str = ft_itoa(game->map->tempc - game->map->coins);
	mlx_string_put(game->mlx, game->window, 180, 115, 0xffffff, str);
	free(str);
	mlx_string_put(game->mlx, game->window, 5, 10, 0xffffff,
		"POWERED BY: SSIBAI");
}

void	rendermap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	if (game->death == 0)
		renderelements(game);
	rendertext(game);
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

static void	rendersonic(t_game *game, int i, int j)
{
	if (game->move == 5 && game->map->map[i - 1][j] != WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->dash[0], j * TILE, i * TILE);
	else if (game->move == 6 && game->map->map[i + 1][j] != WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->dash[1], j * TILE, i * TILE - 120);
	else if (game->move == 7 && game->map->map[i][j - 1] != WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->dash[2], j * TILE, i * TILE);
	else if (game->move == 8 && game->map->map[i][j + 1] != WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->dash[3], j * TILE - 120, i * TILE);
	else if (game->dir == LEFTDIR && game->idle > 300)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[4], j * TILE, i * TILE);
	else if (game->dir == RIGHTDIR && game->idle > 300)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[5], j * TILE, i * TILE);
	else if (game->dir == LEFTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[6], j * TILE, i * TILE);
	else if (game->dir == RIGHTDIR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sonic[7], j * TILE, i * TILE);
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
					game->rings[game->ringsframe / 3], j * TILE, i * TILE);
			if (game->map->map[i][j] == PLAYER)
				rendersonic(game, i, j);
			if (game->map->map[i][j] == ENEMY)
				rendermetalsonic(game, i, j);
			if (game->map->map[i][j] == SPIKES)
				mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[3], j * TILE, i * TILE);
		}
		j = -1;
	}
}
