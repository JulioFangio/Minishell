/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:34:13 by juduval           #+#    #+#             */
/*   Updated: 2023/09/18 14:12:57 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	how_long(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == c && line[i - 1] != 32 && line[i - 1] != c)
			count++;
		if (line[i] == c && line[i + 1] != 32 && line[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

char	*tronc_optn(char *tab)
{
	int		len;
	int		i;
	int		j;
	char	*tronc;

	i = 1;
	j = 0;
	len = ft_strlen(tab);
	if (len == 2)
		return (NULL);
	tronc = ft_calloc(len + 1, sizeof(char));
	if (!tronc)
		return (NULL);
	while (i < len - 1)
	{
		if (tab[i] == '`')
			tronc[j] = 32;
		else
			tronc[j] = tab[i];
		i++;
		j++;
	}
	return (tronc);
}

int	check_quotes(char *line)
{
	size_t	i;
	char	c;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			c = line[i];
			i++;
			while (line[i] && line[i] != c)
				i++;
			if (line[i] == '\0')
				return (0);
			c = '\0';
		}
		i++;
	}
	if (c != '\0')
		return (0);
	return (1);
}

int	check_line(char *line)
{
	if (!check_quotes(line))
		return (0);
	return (1);
}

// char	*keep_spaces(char *line)
// {
// 	char	*res;
// 	int		i;
// 	char	b;

// 	i = 0;
// 	res = ft_calloc(ft_strlen(line) + 1, sizeof(char));
// 	while (line[i])
// 	{
// 		if (line[i] == 34 || line[i] == 39)
// 		{
// 			b = line[i];
// 			while (line[i] != b)
// 			{
// 				if (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))
// 					res[i] = '`';
// 				else
// 					res[i] = line[i];
// 				i++;
// 			}
// 			continue ;
// 		}
// 		res[i] = line[i];
// 		i++;
// 	}
// 	return (res);
// }