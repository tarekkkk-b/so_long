/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:51:34 by tabadawi          #+#    #+#             */
/*   Updated: 2024/04/05 13:08:31 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/***************************************************************/
/*							libraries						  */
/*************************************************************/

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/***************************************************************/
/*							defs							  */
/*************************************************************/

# define WALL				'1'
# define FLOOR				'0'
# define COIN				'C'
# define PLAYER				'P'
# define EXIT				'E'
# define SPIKES				'S'
# define ENEMY				'M'
# define LEFTDIR			1
# define RIGHTDIR			2
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
	int		enemies;
	int		x;
	int		exitx;
	int		y;
	int		exity;
	int		enemyy;
	int		lasty;
	int		enemyx;
	int		lastx;
}	t_parsemap;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*tiles[4];
	void		*sonic[8];
	void		*enemy[4];
	void		*dash[4];
	void		*exit[1];
	void		*supersonic[1];
	void		*rings[8];
	int			ringsframe;
	int			exitflag;
	int			alive;
	int			speed;
	int			end;
	int			tile;
	int			enemydir;
	int			idle;
	int			moves;
	int			change;
	int			controls;
	int			move;
	int			game;
	int			dir;
	int			render;
	int			death;
	int			newx;
	int			newy;
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

void	death(t_game *game);
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
int		handle_keys(int keycode, t_game *game);
void	initialize_tiles(t_game *game);
void	rendermap(t_game *game);
void	renderborders(t_game *game);
void	renderelements(t_game *game);
void	exittilehandling(t_game *game, int newx, int newy);
void	change_frames(int newx, int newy, t_game *game);
void	move(int newx, int newy, t_game *game);
void	initialize_rings(t_game *game);
void	initialize_dash(t_game *game);
void	initialize_sonic(t_game *game);
void	rendertext(t_game *game);
int		update(t_game *game);
void	dashup(t_game *game);
void	dashdown(t_game *game);
void	dashleft(t_game *game);
void	dashright(t_game *game);
void	checkdash(t_game *game);
void	couldntfindimage(t_game *game);
void	destroydash(t_game *game);
void	destroytiles(t_game *game);
void	destroysonic(t_game *game);
char	**setlist(void);
void	destroyrings(t_game *game);
void	checkimages(char **set);
void	attack(t_game *game, int newx, int newy);
void	randomizer(t_game *game);
void	enemymove(t_game *game, int newx, int newy);
void	validatedash(int keycode, t_game *game);
void	rendermetalsonic(t_game *game, int i, int j);
void	renderdedmetalsonic(t_game *game);
void	renderwinningscreen(t_game *game);

#endif