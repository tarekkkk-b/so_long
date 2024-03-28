/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:52:39 by tabadawi          #+#    #+#             */
/*   Updated: 2023/12/12 10:13:42 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putusnbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 2));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(c));
}
