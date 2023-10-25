/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:10:14 by juduval           #+#    #+#             */
/*   Updated: 2023/10/25 19:39:30 by jaristil         ###   ########.fr       */
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

int	check_first_token_for_each_pipe(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (!is_there_a_pipe(data->token))
		return (parse_first_token(data->token));
	while (is_there_a_pipe(tmp))
	{
		if (!parse_first_token(tmp))
			return (0);
		while (tmp->type != 3)
			tmp = tmp->next;
		tmp = tmp->next;
	}
	return (parse_first_token(tmp));
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
