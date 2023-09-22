/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:53:31 by juduval           #+#    #+#             */
/*   Updated: 2023/09/22 12:22:10 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	whole_count(char *line)
{
	int	i;

	i = how_long(line, '<') + how_long(line, '>') + how_long(line, '|')
		+ how_long(line, '=') + how_long(line, '&');
	return (i);
}

static int	is_sep(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '=' || c == '&')
		return (1);
	return (0);
}

char	*make_spaces(char *line, char *res, size_t i, int j)
{
	while (line[i])
	{
		if (i > 0 && is_sep(line[i])
			&& !is_sep(line[i - 1]) && line[i - 1] != 32)
		{
			res[j] = ' ';
			j++;
			res[j] = line[i];
		}
		if (i < ft_strlen(line) && is_sep(line[i])
			&& !is_sep(line[i + 1]) && line[i + 1] != 32)
		{
			res[j] = line[i];
			j++;
			res[j] = ' ';
		}
		else
			res[j] = line[i];
		j++;
		i++;
	}
	return (res);
}

int	shorten(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] == '(')
		{
			while (line[i] && line[i] != ')')
			{
				if (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))
					count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

char	*remove_spaces(char *line, int i, int j)
{
	char	*res;
	int		check;

	check = 0;
	res = ft_calloc((ft_strlen(line) - shorten(line)) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] == '(')
			check = 1;
		else if (line[i] == ')')
			check = 0;
		if ((line[i] == 32 || (line[i] >= 9 && line[i] <= 13)) && check == 1)
		{
			i++;
			continue ;
		}
		res[j] = line[i];
		i++;
		j++;
	}
	return (res);
}

