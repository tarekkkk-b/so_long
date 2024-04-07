/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:24:10 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:37:59 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == WALL
		|| (game->map->map[y][x] == EXIT && game->exitflag == 1))
	{
		game->move = 0;
		game->controls = 1;
		if (game->change != 0)
			ft_printf("Number of moves: %d\n", ++game->moves);
		game->change = 0;
		return (-1);
	}
	return (0);
}

void	dashup(t_game *game)
{
	game->controls = 0;
	if (check(game, game->map->x, game->map->y - 1) == -1)
		return ;
	if (game->map->map[game->map->y - 1][game->map->x] == COIN)
		game->map->coins--;
	if (game->map->map[game->map->y - 1][game->map->x] == SPIKES)
		return (death(game));
	if (game->map->map[game->map->y - 1][game->map->x] == ENEMY)
		return (attack(game, game->map->x, game->map->y - 1));
	if (game->wasexit == 1)
	{
		game->map->map[game->map->y][game->map->x] = EXIT;
		game->wasexit = 0;
	}
	else
		game->map->map[game->map->y][game->map->x] = FLOOR;
	if (game->map->map[game->map->y - 1][game->map->x] == EXIT)
		game->wasexit = 1;
	game->map->map[game->map->y - 1][game->map->x] = PLAYER;
	game->map->y = game->map->y - 1;
	game->change++;
	game->idle = 0;
}

void	dashdown(t_game *game)
{
	game->controls = 0;
	if (check(game, game->map->x, game->map->y + 1) == -1)
		return ;
	if (game->map->map[game->map->y + 1][game->map->x] == COIN)
		game->map->coins--;
	if (game->map->map[game->map->y + 1][game->map->x] == SPIKES)
		return (death(game));
	if (game->map->map[game->map->y + 1][game->map->x] == ENEMY)
		return (attack(game, game->map->x, game->map->y + 1));
	if (game->wasexit == 1)
	{
		game->map->map[game->map->y][game->map->x] = EXIT;
		game->wasexit = 0;
	}
	else
		game->map->map[game->map->y][game->map->x] = FLOOR;
	if (game->map->map[game->map->y + 1][game->map->x] == EXIT)
		game->wasexit = 1;
	game->map->map[game->map->y + 1][game->map->x] = PLAYER;
	game->map->y = game->map->y + 1;
	game->change++;
	game->idle = 0;
}

void	dashleft(t_game *game)
{
	game->controls = 0;
	game->dir = LEFTDIR;
	if (check(game, game->map->x - 1, game->map->y) == -1)
		return ;
	if (game->map->map[game->map->y][game->map->x - 1] == COIN)
		game->map->coins--;
	if (game->map->map[game->map->y][game->map->x - 1] == SPIKES)
		return (death(game));
	if (game->map->map[game->map->y][game->map->x - 1] == ENEMY)
		return (attack(game, game->map->x - 1, game->map->y));
	if (game->wasexit == 1)
	{
		game->map->map[game->map->y][game->map->x] = EXIT;
		game->wasexit = 0;
	}
	else
		game->map->map[game->map->y][game->map->x] = FLOOR;
	if (game->map->map[game->map->y][game->map->x - 1] == EXIT)
		game->wasexit = 1;
	game->map->map[game->map->y][game->map->x - 1] = PLAYER;
	game->map->x = game->map->x - 1;
	game->change++;
	game->idle = 0;
}

void	dashright(t_game *game)
{
	game->dir = RIGHTDIR;
	game->controls = 0;
	if (check(game, game->map->x + 1, game->map->y) == -1)
		return ;
	if (game->map->map[game->map->y][game->map->x + 1] == COIN)
		game->map->coins--;
	if (game->map->map[game->map->y][game->map->x + 1] == SPIKES)
		return (death(game));
	if (game->map->map[game->map->y][game->map->x + 1] == ENEMY)
		return (attack(game, game->map->x + 1, game->map->y));
	if (game->wasexit == 1)
	{
		game->map->map[game->map->y][game->map->x] = EXIT;
		game->wasexit = 0;
	}
	else
		game->map->map[game->map->y][game->map->x] = FLOOR;
	if (game->map->map[game->map->y][game->map->x + 1] == EXIT)
		game->wasexit = 1;
	game->map->map[game->map->y][game->map->x + 1] = PLAYER;
	game->map->x = game->map->x + 1;
	game->change++;
	game->idle = 0;
}
