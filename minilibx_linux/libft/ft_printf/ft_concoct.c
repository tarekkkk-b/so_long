/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concoct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:48:45 by enoshahi          #+#    #+#             */
/*   Updated: 2024/09/04 17:43:32 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_concoct(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_putusd(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 'x'));
	if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 'X'));
	if (format == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}
