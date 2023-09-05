/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:34:13 by juduval           #+#    #+#             */
/*   Updated: 2023/09/05 18:09:19 by juduval          ###   ########.fr       */
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

	i = 0;
	j = 0;
	len = ft_strlen(tab) - 1;
	tronc = ft_calloc(len, sizeof(char));
	if (!tronc)
		return (NULL);
	while (tab[i] == 34 || tab[i] == 39)
		i++;
	while (tab[len] == 34 || tab[len] == 39)
		len--;
	while (i < len + 1)
	{
		tronc[j] = tab[i];
		i++;
		j++;
	}
	return (tronc);
}

int	check_dquotes(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 34)
		{
			while (line[i] && line[i] == 34)
				i++;
			while (line[i] && line[i] != 34)
				i++;
			if (line[i] == '\0')
				return (0);
			else
				while (line[i] && line[i] == 34)
					i++;
		}
		i++;
	}
	return (1);
}

int	check_quotes(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 39)
		{
			while (line[i] && line[i] == 39)
				i++;
			while (line[i] && line[i] != 39)
				i++;
			if (line[i] == '\0')
				return (0);
			else
				while (line[i] && line[i] == 39)
					i++;
		}
		i++;
	}
	return (1);
}

int	check_line(char *line)
{
	if (!check_dquotes(line) || !check_quotes(line))
		return (0);
	return (1);
}
