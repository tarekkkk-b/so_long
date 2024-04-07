/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:14:41 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:36:54 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	checkwinflag(t_game *game)
{
	int	i;

	if (game->exitcollected == 1)
	{
		i = 0;
		while (i < 600000000)
			i++;
		i = 0;
		renderwinningscreen(game);
	}
}

static void	checkflags(t_game *game)
{
	int	i;

	if (game->death == 1)
	{
		i = 0;
		while (i < 600000000)
			i++;
		gameover(game);
	}
	if (game->moves == 500)
	{
		ft_printf("You really suck at this game huh?\n");
		gameover(game);
	}
}

void	checkdash(t_game *game)
{
	if (game->move == 5)
		dashup(game);
	if (game->move == 6)
		dashdown(game);
	if (game->move == 7)
		dashleft(game);
	if (game->move == 8)
		dashright(game);
}

int	update(t_game *game)
{
	if (game->game == 1)
	{
		game->ringsframe = (game->ringsframe + 1) % (8 * 3);
		game->speed = (game->speed + 1) % 8;
		game->idle++;
		if (game->idle > 500)
			game->idle = 301;
		checkflags(game);
		rendermap(game);
		if (game->alive == 0)
			renderdedmetalsonic(game);
		checkdash(game);
		if (game->alive == 1 && game->speed == 0)
			randomizer(game);
		if (game->map->coins == 0)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->exit[0],
				game->map->exitx * TILE, game->map->exity * TILE);
			game->exitflag = 1;
		}
	}
	else
		(checkwinflag(game), game->end++);
	return (0);
}
