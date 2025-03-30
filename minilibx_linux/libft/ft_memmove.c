/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:06:21 by enoshahi          #+#    #+#             */
/*   Updated: 2024/08/11 12:11:49 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_usc		*dst_t;
	const t_usc	*src_t;

	if (!dst && !src)
		return (NULL);
	dst_t = (t_usc *)dst;
	src_t = (const t_usc *)src;
	if (dst_t > src_t && src_t + len > dst_t)
		while (len-- > 0)
			dst_t[len] = src_t[len];
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
