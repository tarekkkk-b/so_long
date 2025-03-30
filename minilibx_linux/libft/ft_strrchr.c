/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:18:06 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 12:14:17 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	curr;
	char	*res;
	size_t	i;

	i = 0;
	curr = (char) c;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == curr)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == curr)
	{
		res = (char *)&s[i];
		i++;
	}
	return (res);
}
