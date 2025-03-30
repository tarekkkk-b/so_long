/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:34:29 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/24 14:24:00 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char dl)
{
	int	words;
	int	x;

	words = 0;
	x = 0;
	while (*s)
	{
		if (*s != dl && x == 0)
		{
			x = 1;
			words++;
		}
		else if (*s == dl && x == 1)
			x = 0;
		s++;
	}
	return (words);
}

static int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

static char	**ft_splitalloc(char **str, char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_wordlen(s, c);
			str[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!str[i])
			{
				ft_free(str);
				return (NULL);
			}
			ft_strlcpy(str[i], s, len + 1);
			str[i][len] = '\0';
			i++;
			s += len;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	return (ft_splitalloc(strs, (char *)s, c));
}
