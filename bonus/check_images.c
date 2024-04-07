/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:24:00 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 13:50:52 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**setlist(void)
{
	static char	*list[30] = {
		"./bonus/textures/xpm/border.xpm", "./bonus/textures/xpm/wall.xpm",
		"./bonus/textures/xpm/floor.xpm", "./bonus/textures/xpm/spikes.xpm",
		"./bonus/textures/xpm/emerald.xpm", "./bonus/textures/xpm/ring1.xpm",
		"./bonus/textures/xpm/ring2.xpm", "./bonus/textures/xpm/ring3.xpm",
		"./bonus/textures/xpm/ring4.xpm", "./bonus/textures/xpm/dashdown.xpm",
		"./bonus/textures/xpm/ring6.xpm", "./bonus/textures/xpm/ring7.xpm",
		"./bonus/textures/xpm/ring8.xpm", "./bonus/textures/xpm/idleleft.xpm",
		"./bonus/textures/xpm/dashleft.xpm",
		"./bonus/textures/xpm/dashright.xpm",
		"./bonus/textures/xpm/sonicright.xpm",
		"./bonus/textures/xpm/sonicleft.xpm",
		"./bonus/textures/xpm/sonicwinright.xpm",
		"./bonus/textures/xpm/sonicwinleft.xpm",
		"./bonus/textures/xpm/dieleft.xpm", "./bonus/textures/xpm/ring5.xpm",
		"./bonus/textures/xpm/dieright.xpm",
		"./bonus/textures/xpm/idleright.xpm", "./bonus/textures/xpm/dashup.xpm",
		"./bonus/textures/xpm/enemydedleft.xpm",
		"./bonus/textures/xpm/enemydedright.xpm",
		"./bonus/textures/xpm/enemyleft.xpm",
		"./bonus/textures/xpm/enemyright.xpm",
		"./bonus/textures/xpm/supersonic.xpm"
	};

	return (list);
}

void	checkimages(char **set)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 30)
	{
		fd = open(set[i], O_RDONLY);
		if (fd == -1)
			(write (2, "Couldn't find image.\n", 21), exit (EF));
		close (fd);
		i++;
	}
}
