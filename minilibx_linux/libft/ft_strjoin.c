/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:45:18 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 13:12:31 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcat(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, (ft_strlen(s1) + ft_strlen(s2)) + 1);
	return (res);
}
