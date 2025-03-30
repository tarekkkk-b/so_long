/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:47:34 by enoshahi          #+#    #+#             */
/*   Updated: 2024/09/04 17:22:33 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, char base)
{
	char	*hex;
	int		count;

	count = 0;
	if (base == 'x')
		hex = "0123456789abcdef";
	else if (base == 'X')
		hex = "0123456789ABCDEF";
	if (num > 15)
		count = ft_puthex(num / 16, base);
	if (count == -1)
		return (-1);
	if (ft_putchar(hex[num % 16]) == -1)
		return (-1);
	return (count + 1);
}
