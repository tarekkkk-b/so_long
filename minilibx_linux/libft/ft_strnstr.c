/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:21:26 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 13:12:31 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			j++;
			if (!little[j])
				return ((char *) big + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
