/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:53:31 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:39:41 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	whole_count(char *line)
{
	int	i;

	i = how_long(line, '<', 0, 0) + how_long(line, '>', 0, 0)
		+ how_long(line, '|', 0, 0);
	return (i);
}

static int	is_sep(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	front_or_back_space(char *line, char *res, size_t i, int j)
{
	if (i > 0 && is_sep(line[i])
		&& !is_sep(line[i - 1]) && line[i - 1] != 32)
	{
		res[j] = ' ';
		j++;
		res[j] = line[i];
		return (1);
	}
	if (i < ft_strlen(line) && is_sep(line[i])
		&& !is_sep(line[i + 1]) && line[i + 1] != 32)
	{
		res[j] = line[i];
		j++;
		res[j] = ' ';
		return (1);
	}
	return (0);
}

char	*make_spaces(char *line, char *res, size_t i, int j)
{
	size_t	n;
	int		len;

	len = j;
	n = 0;
	j = 0;
	while (line[i] && i < ft_strlen(line) && j < len)
	{
		n = skip_quotes(line, i);
		while (i < n)
		{
			res[j] = line[i];
			j++;
			i++;
		}
		if (j < len - 1 && front_or_back_space(line, res, i, j))
			j++;
		else
			res[j] = line[i];
		j++;
		i++;
	}
	return (res);
}
