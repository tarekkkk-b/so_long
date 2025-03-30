/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:31:56 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/24 14:29:08 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	if (ft_putstr("0x") == -1)
		return (-1);
	count = ft_puthex(ptr, 'x');
	if (count == 0)
		return (write(1, "0", 1));
	if (count == -1)
		return (-1);
	return (count + 2);
}
