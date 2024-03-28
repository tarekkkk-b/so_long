/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:40:36 by tabadawi          #+#    #+#             */
/*   Updated: 2023/12/12 11:14:02 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putpointer(void *p)
{
	int	res;

	res = 0;
	res += ft_putstr("0x");
	res += ft_puthex((unsigned long)p, 1);
	return (res);
}
