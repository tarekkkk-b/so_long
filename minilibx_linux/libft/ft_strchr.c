/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:05:15 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 12:12:32 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	curr;

	curr = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == curr)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == curr)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
