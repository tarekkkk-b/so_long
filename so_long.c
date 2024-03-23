/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:05:54 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/23 11:52:55 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	if (ac != 2)
	{
		write(2, "Usage: ./so_long [map].ber\n", 28);
		exit (EXIT_FAILURE);
	}
	map = parse_map(av[1]);
	return (0);
}