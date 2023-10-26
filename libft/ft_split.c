/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:21:18 by jaristil          #+#    #+#             */
/*   Updated: 2023/08/01 17:00:50 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static	char	*ft_strdup_split(const char *s, char c)
{
	char	*dup;
	size_t	i;
	size_t	j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	dup = malloc(sizeof(char) * (j + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i < j)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	*ft_free(char **s, size_t j)
{
	while (j-- > 0)
		free(s[j]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	split = ft_calloc(sizeof(char *), (ft_size_word(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			split[j] = ft_strdup_split(s + i, c);
			if (!split[j])
				return (ft_free(split, j));
		}
		while (s[i] && s[i] != c)
			i++;
		if (s[i])
			j++;
	}
	return (split);
}
