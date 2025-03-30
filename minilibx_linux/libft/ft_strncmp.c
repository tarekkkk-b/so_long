/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:16:04 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 13:12:31 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((t_usc)s1[i] != (t_usc)s2[i])
			return ((t_usc)s1[i] - (t_usc)s2[i]);
		i++;
	}
	return (0);
}
