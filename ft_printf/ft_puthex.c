/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:39:47 by tabadawi          #+#    #+#             */
/*   Updated: 2023/12/12 11:03:51 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int	ft_counter(unsigned long nbr)
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
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned long long nbr, unsigned int letter)
{
	char	*hex1;
	char	*hex2;
	int		count;

	hex1 = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	count = ft_counter(nbr);
	if (letter == 1)
	{
		if (nbr >= 16)
			ft_puthex(nbr / 16, 1);
		write(1, &hex1[nbr % 16], 1);
	}
	else if (letter == 2)
	{
		if (nbr >= 16)
			ft_puthex(nbr / 16, 2);
		write(1, &hex2[nbr % 16], 1);
	}
	else
		return (-1);
	return (count);
}
