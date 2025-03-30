/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:41:18 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 13:35:35 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(unsigned int nb, int mult)
{
	if (nb > 2147483647 && mult == 1)
		return (-1);
	else if (nb > 2147483648 && mult == -1)
		return (0);
	nb *= mult;
	return (nb);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if ((str[i] == '-' || str[i] == '+') && (str[i++] == '-'))
			sign = -1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i++] - '0');
		}
		return (check(res, sign));
	}
	return (0);
}
