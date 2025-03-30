/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:08:22 by enoshahi          #+#    #+#             */
/*   Updated: 2024/09/04 17:38:02 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789";
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count = ft_putnbr(-num);
		if (count == -1)
			return (-1);
		return (count + 1);
	}
	if (num > 9)
		count = ft_putnbr(num / 10);
	if (count == -1)
		return (-1);
	if (ft_putchar(str[num % 10]) == -1)
		return (-1);
	return (count + 1);
}
