/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:20:27 by juduval           #+#    #+#             */
/*   Updated: 2023/09/12 16:59:39 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_isseparator(char c, char sep)
{
	if (c == sep || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}

static	int	ft_countwords(const char *str, char sep)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isseparator(str[i], sep))
			i++;
		else
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
	}
	return (count);
}

static	char	*ft_strdupbis(const char *s, char sep)
{
	int		size;
	char	*copy;

	size = 0;
	while (s[size] != sep && s[size])
		size++;
	copy = ft_calloc(size + 1, sizeof(char));
	if (!(s))
		return (NULL);
	size = 0;
	while (s[size] && s[size] != sep)
	{
		copy[size] = s[size];
		size++;
	}
	copy[size] = '\0';
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
	ns = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!(ns))
		return (0);
	if (ft_countwords(s, c) == 0)
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
/*
int	main(void)
{
	char	**split;
	char	s[] = "lorem ipsum dolor sit amet, consectetur
		adipiscing elit. Sed non risus. Suspendisse";
	char	c = ' ';
	int	i;

	i = 0;
	split = split_mini(s, c);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}*/
