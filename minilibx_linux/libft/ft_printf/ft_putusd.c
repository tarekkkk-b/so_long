/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:42:30 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/24 14:26:57 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putusd(unsigned int num)
{
	int		count;
	char	*str;

	count = 0;
	str = "0123456789";
	if (num > 9)
		count = ft_putusd(num / 10);
	if (count == -1)
		return (-1);
	if (ft_putchar(str[num % 10]) == -1)
		return (-1);
	return (count + 1);
}
