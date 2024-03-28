/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:13 by tabadawi          #+#    #+#             */
/*   Updated: 2024/03/04 22:10:24 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		sum;
	int		temp;

	va_start(arg, str);
	sum = 0;
	i = 0;
	while (str[i])
	{
		temp = sum;
		if (str[i] == '%')
			sum += (ft_format(str[++i], arg));
		else
			sum += ft_putchar(str[i]);
		if (sum < temp)
			return (-1);
		i++;
	}
	va_end(arg);
	return (sum);
}
