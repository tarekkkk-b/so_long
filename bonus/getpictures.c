/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpictures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:23:18 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 12:56:24 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_tiles(t_game *game)
{
	game->tiles[0] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/border.xpm", &game->tile, &game->tile);
	game->tiles[1] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/wall.xpm", &game->tile, &game->tile);
	game->tiles[2] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/floor.xpm", &game->tile, &game->tile);
	game->tiles[3] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/spikes.xpm", &game->tile, &game->tile);
	game->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/emerald.xpm", &game->tile, &game->tile);
	game->enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/enemyleft.xpm", &game->tile, &game->tile);
	game->enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/enemyright.xpm", &game->tile, &game->tile);
	game->enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/enemydedright.xpm", &game->tile, &game->tile);
	game->enemy[3] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/enemydedleft.xpm", &game->tile, &game->tile);
	game->supersonic[0] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/supersonic.xpm", &game->tile, &game->tile);
}

void	initialize_rings(t_game *game)
{
	game->rings[0] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring1.xpm", &game->tile, &game->tile);
	game->rings[1] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring2.xpm", &game->tile, &game->tile);
	game->rings[2] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring3.xpm", &game->tile, &game->tile);
	game->rings[3] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring4.xpm", &game->tile, &game->tile);
	game->rings[4] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring5.xpm", &game->tile, &game->tile);
	game->rings[5] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring6.xpm", &game->tile, &game->tile);
	game->rings[6] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring7.xpm", &game->tile, &game->tile);
	game->rings[7] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/ring8.xpm", &game->tile, &game->tile);
}

void	initialize_dash(t_game *game)
{
	game->dash[0] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/dashup.xpm", &game->tile, &game->tile);
	game->dash[1] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/dashdown.xpm", &game->tile, &game->tile);
	game->dash[2] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/dashleft.xpm", &game->tile, &game->tile);
	game->dash[3] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/dashright.xpm", &game->tile, &game->tile);
}

void	initialize_sonic(t_game *game)
{
	game->sonic[0] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/sonicwinleft.xpm", &game->tile, &game->tile);
	game->sonic[1] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/sonicwinright.xpm", &game->tile, &game->tile);
	game->sonic[2] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/dieleft.xpm", &game->tile, &game->tile);
	game->sonic[3] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/dieright.xpm", &game->tile, &game->tile);
	game->sonic[4] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/idleleft.xpm", &game->tile, &game->tile);
	game->sonic[5] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/idleright.xpm", &game->tile, &game->tile);
	game->sonic[6] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/sonicleft.xpm", &game->tile, &game->tile);
	game->sonic[7] = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/xpm/sonicright.xpm", &game->tile, &game->tile);
}
