/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:20:27 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:30:21 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_size(const char *s, char sep)
{
	int		len;
	char	b;

	len = 0;
	while (s[len] != sep && s[len])
	{
		if (s[len] == '"' || s[len] == '\'')
		{
			b = s[len];
			len++;
			while (s[len] != b)
				len++;
			len++;
		}
		else
			len++;
	}
	return (len + 1);
}

static void	fill_split(const char *s, char *copy, char sep)
{
	char	b;
	int		i;

	i = 0;
	while (s[i] && s[i] != sep)
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			b = s[i];
			copy[i] = s[i];
			i++;
			while (s[i] != b)
			{
				copy[i] = s[i];
				i++;
			}
			copy[i] = s[i];
			i++;
		}
		else
		{
			copy[i] = s[i];
			i++;
		}
	}
}

static	char	*ft_strdupbis(const char *s, char sep)
{
	int		size;
	char	*copy;

	size = get_size(s, sep);
	copy = ft_calloc(size + 1, sizeof(char));
	if (!(s))
		return (NULL);
	size = 0;
	fill_split(s, copy, sep);
	return (copy);
}

static	char	**ft_free(char **s, int j)
{
	while (j >= 0)
	{
		free(s[j]);
		j--;
	}
	free(s);
	return (NULL);
}

char	**split_mini(char const *s, char c)
{
	int		i;
	int		j;
	char	**ns;

	i = 0;
	j = 0;
	ns = ft_calloc((ft_countwords(s, c, 0, 0) + 1), sizeof(char *));
	if (!(ns))
		return (0);
	if (ft_countwords(s, c, 0, 0) == 0)
		return (ns);
	while (s[i])
	{
		if (ft_isseparator(s[i], c))
			i++;
		else
		{
			ns[j] = ft_strdupbis(s + i, c);
			if (!(ns[j]))
				return (ft_free(ns, j));
			i += ft_strlen(ns[j++]);
		}
	}
	return (ns);
}
