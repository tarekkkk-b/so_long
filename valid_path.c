/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarekkkk <tarekkkk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:33:10 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/25 21:08:57 by tarekkkk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_path(char **copy, int x, int y, t_parsemap **prsng)
{
	if (x < 0 || x > (*prsng)->cols || y < 0
		|| y > (*prsng)->rows || copy[y][x] == WALL)
		return ;
	if (copy[y][x] == COIN)
		(*prsng)->coins--;
	if (copy[y][x] == EXIT)
		(*prsng)->exit--;
	copy[y][x] = '1';
	validate_path(copy, x + 1, y, prsng);
	validate_path(copy, x - 1, y, prsng);
	validate_path(copy, x, y + 1, prsng);
	validate_path(copy, x, y - 1, prsng);
}
