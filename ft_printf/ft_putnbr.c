/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:27:18 by tabadawi          #+#    #+#             */
/*   Updated: 2023/12/12 11:10:27 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
	{
		len = 1;
		return (len);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
	}
	else if (nbr <= 9)
		ft_putchar(nbr + '0');
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	return (ft_getlen(nbr));
}
