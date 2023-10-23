/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:10:14 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:41:47 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_end(char *line, int i, char c)
{
	while (line[i] && line[i] == c)
		i++;
	while (line[i] && line[i] != c)
		i++;
	while (line[i] && line[i] == c)
		i++;
	return (i);
}

char	*remake_line(char *line, int n, int l)
{
	char	*res;

	res = ft_calloc(l + n + 1, sizeof(char));
	if (!res)
		return (NULL);
	res = make_spaces(line, res, 0, (l + n));
	return (res);
}
