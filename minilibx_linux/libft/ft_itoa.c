/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:50:43 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/04 23:50:44 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_numlen(n);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	res[i] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
