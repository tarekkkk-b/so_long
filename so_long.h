/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:51:34 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/23 14:43:39 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define WALL				'1'
# define FLOOR				'0'
# define COIN				'C'
# define PLAYER				'P'
# define EXIT				'E'

typedef struct s_parsemap
{
	int		fd;
	int		check;
	int		rows;
	int		emptyline;
	char	*line;
	char	**map;
	char	**copy;
}	t_parsemap;

#endif