/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarekkkk <tarekkkk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:51:34 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/27 00:21:58 by tarekkkk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/***************************************************************/
/*							libraries						  */
/*************************************************************/

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

/***************************************************************/
/*							defs							  */
/*************************************************************/

# define WALL				'1'
# define FLOOR				'0'
# define COIN				'C'
# define PLAYER				'P'
# define EXIT				'E'

/***************************************************************/
/*							structs							  */
/*************************************************************/

typedef struct s_parsemap
{
	int		fd;
	int		rows;
	int		cols;
	int		emptyline;
	char	*line;
	char	**map;
	char	**copy;
	int		coins;
	int		tempc;
	int		player;
	int		exit;
	int		tempe;
	int		x;
	int		y;
}	t_parsemap;

/***************************************************************/
/*							functions						  */
/*************************************************************/

void	parse_map(char *path, t_parsemap *prsng);
void	linecount(char *path, t_parsemap **prsng);
void	validate_size(t_parsemap **prsng);
void	mapclosed(t_parsemap **prsng);
void	get_map(char *path, t_parsemap **prsng);
void	validate_elements(t_parsemap **prsng);
void	freeing(char **map, char **copy);
void	validate_file(char *path);
int		check_occurance(char *row, char c);
void	validate_char(t_parsemap **prsng, char c);
void	initializer(t_parsemap **prsng);
void	validate_path(char **copy, int x, int y, t_parsemap **prsng);

#endif