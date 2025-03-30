/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:52:29 by enoshahi          #+#    #+#             */
/*   Updated: 2024/09/04 17:38:28 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			count += ft_putchar(str[i]);
			i++;
		}
		if (str[i] != '\0')
		{
			count += ft_concoct(args, str[i + 1]);
			i += 2;
		}
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	int r = ft_printf("%d", 10);
// 	ft_printf("\nr:%i\n",r);
// }
