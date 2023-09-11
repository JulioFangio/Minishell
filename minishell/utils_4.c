/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:10:14 by juduval           #+#    #+#             */
/*   Updated: 2023/09/11 15:59:58 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remake_line(char *line, int n, int l)
{
	char	*res;
	char	*res2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc(l + n + 1, sizeof(char));
	if (!res)
		return (NULL);
	res2 = remove_spaces(make_spaces(line, res), i, j);
	free(res);
	return (res2);
}
