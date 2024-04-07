/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkimages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:38:16 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 13:08:07 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**setlist(void)
{
	static char	*list[7] = {
		"./mand/textures/xpm/border.xpm", "./mand/textures/xpm/wall.xpm",
		"./mand/textures/xpm/floor.xpm",	"./mand/textures/xpm/emerald.xpm",
		"./mand/textures/xpm/ring.xpm", "./mand/textures/xpm/sonic.xpm",
		"./mand/textures/xpm/sonicwin.xpm"
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
