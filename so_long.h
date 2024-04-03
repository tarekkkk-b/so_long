/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:51:34 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/03 13:40:51 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/***************************************************************/
/*							libraries						  */
/*************************************************************/

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "ft_printf/ft_printf.h"
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
# define EF					EXIT_FAILURE
# define ES					EXIT_SUCCESS
# define TILE				120

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
	int		tempe;
	int		exit;
	int		player;
	int		x;
	int		exitx;
	int		y;
	int		exity;
}	t_parsemap;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*tiles[3];
	void		*coins[1];
	void		*sonic[2];
	int			exitflag;
	void		*exit[1];
	int			tile;
	int			moves;
	int			controls;
	int			wasexit;
	int			exitcollected;
	t_parsemap	*map;
}	t_game;

typedef enum keys
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	W = 13,
	A= 0,
	S = 1,
	D = 2,
	ESC = 53
}	t_keys;

/***************************************************************/
/*							functions						  */
/*************************************************************/

void	parse_map(char *path, t_game *map);
void	linecount(char *path, t_parsemap **prsng);
void	validate_size(t_parsemap **prsng);
void	mapclosed(t_parsemap **prsng);
void	get_map(char *path, t_parsemap **prsng);
void	validate_elements(t_parsemap **prsng);
void	freeing(char **map, char **copy, t_parsemap *prsng);
void	validate_file(char *path, t_parsemap **prsng);
int		check_occurance(char *row, char c);
void	validate_char(t_parsemap **prsng, char c);
void	initializer(t_parsemap **prsng);
void	validate_path(char **copy, int x, int y, t_parsemap **prsng);
void	destroysprites(t_game *game);
int		gameover(t_game *game);
void	game_won(t_game *game);
int		checkexit(t_game *game);
int		handle_keys(int keycode, t_game *game);
void	initialize_tiles(t_game *game);
void	rendermap(t_game *game);
void	renderborders(t_game *game);
void	renderelements(t_game *game);
void	exittilehandling(t_game *game, int newx, int newy);
void	change_frames(int newx, int newy, t_game *game);
void	move(int newx, int newy, t_game *game);
void	checkimages(char **set);
char	**setlist(void);

#endif