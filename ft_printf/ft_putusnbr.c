/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:40:14 by tabadawi          #+#    #+#             */
/*   Updated: 2023/12/10 11:18:10 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
	{
		len = 1;
		return (len);
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putusnbr(unsigned int nbr)
{
	if (nbr <= 9)
		return (ft_putchar(nbr + '0'));
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	return (ft_getlen(nbr));
}
