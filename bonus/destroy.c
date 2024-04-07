/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:17:43 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 11:37:49 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroysprites(t_game *game)
{
	destroytiles(game);
	destroyrings(game);
	destroysonic(game);
	destroydash(game);
}

void	destroydash(t_game *game)
{
	mlx_destroy_image(game->mlx, game->dash[0]);
	mlx_destroy_image(game->mlx, game->dash[1]);
	mlx_destroy_image(game->mlx, game->dash[2]);
	mlx_destroy_image(game->mlx, game->dash[3]);
}

void	destroytiles(t_game *game)
{
	mlx_destroy_image(game->mlx, game->exit[0]);
	mlx_destroy_image(game->mlx, game->tiles[0]);
	mlx_destroy_image(game->mlx, game->tiles[1]);
	mlx_destroy_image(game->mlx, game->tiles[2]);
	mlx_destroy_image(game->mlx, game->tiles[3]);
	mlx_destroy_image(game->mlx, game->enemy[0]);
	mlx_destroy_image(game->mlx, game->enemy[1]);
	mlx_destroy_image(game->mlx, game->enemy[2]);
	mlx_destroy_image(game->mlx, game->enemy[3]);
	mlx_destroy_image(game->mlx, game->supersonic[0]);
}

void	destroysonic(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sonic[0]);
	mlx_destroy_image(game->mlx, game->sonic[1]);
	mlx_destroy_image(game->mlx, game->sonic[2]);
	mlx_destroy_image(game->mlx, game->sonic[3]);
	mlx_destroy_image(game->mlx, game->sonic[4]);
	mlx_destroy_image(game->mlx, game->sonic[5]);
	mlx_destroy_image(game->mlx, game->sonic[6]);
	mlx_destroy_image(game->mlx, game->sonic[7]);
}

void	destroyrings(t_game *game)
{
	mlx_destroy_image(game->mlx, game->rings[0]);
	mlx_destroy_image(game->mlx, game->rings[1]);
	mlx_destroy_image(game->mlx, game->rings[2]);
	mlx_destroy_image(game->mlx, game->rings[3]);
	mlx_destroy_image(game->mlx, game->rings[4]);
	mlx_destroy_image(game->mlx, game->rings[5]);
	mlx_destroy_image(game->mlx, game->rings[6]);
	mlx_destroy_image(game->mlx, game->rings[7]);
}
