/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:53:29 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 13:11:38 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_usc	*dst_t;
	const t_usc	*src_t;
	size_t		i;

	dst_t = (const t_usc *) s1;
	src_t = (const t_usc *) s2;
	i = 0;
	while (i < n)
	{
		if (dst_t[i] != src_t[i])
			return (dst_t[i] - src_t[i]);
		i++;
	}
	return (0);
}
