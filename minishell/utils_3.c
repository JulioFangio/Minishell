/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:53:31 by juduval           #+#    #+#             */
/*   Updated: 2023/09/05 19:31:15 by juduval          ###   ########.fr       */
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

char	*remake_line(char *line, int n, int l)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc(l + n + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (line[i])
	{
		if (is_sep(line[i]) && !is_sep(line[i - 1]) && line[i - 1] != 32)
		{
			res[j] = ' ';
			j++;
			res[j] = line[i];
		}
		if (is_sep(line[i]) && !is_sep(line[i + 1]) && line[i + 1] != 32)
		{
			res[j] = line[i];
			j++;
			res[j] = ' ';
		}
		else
			res[j] = line[i];
		i++;
		j++;
	}
	return (res);
}
