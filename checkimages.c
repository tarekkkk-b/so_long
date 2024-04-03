/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkimages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:38:16 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/03 13:40:26 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**setlist(void)
{
	static char	*list[7] = {
		"./textures/xpm/border.xpm", "./textures/xpm/wall.xpm",
		"./textures/xpm/floor.xpm",	"./textures/xpm/emerald.xpm",
		"./textures/xpm/ring.xpm", "./textures/xpm/sonic.xpm",
		"./textures/xpm/sonicwin.xpm"
	};

	return (list);
}

void	checkimages(char **set)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 7)
	{
		fd = open(set[i], O_RDONLY);
		if (fd == -1)
			(write (2, "Couldn't find image.\n", 21), exit (EF));
		close (fd);
		i++;
	}
}