/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:49:58 by juduval           #+#    #+#             */
/*   Updated: 2023/10/25 16:06:56 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quotes(char *line)
{
	size_t	i;
	char	c;

	i = 0;
	c = '\0';
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

static int	only_slash(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != '/')
			return (0);
		i++;
	}
	return (1);
}

int	parse_first_token(t_token *token)
{
	if (!token->next && (!ft_strcmp(token->str, "!")
			|| !ft_strcmp(token->str, ":")))
		return (0);
	else if (token->str && token->str[0] == '/'
		&& token->str[1] && token->str[1] != '/')
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(" : is a directory", STDERR);
		return (0);
	}
	else if (token->str && !token->next && (token->str[0] == '/'
			&& only_slash(token->str) && ((!token->str[1])
				|| token->str[1] == '.' || token->str[1] == '/')))
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(" : is a directory", STDERR);
		return (0);
	}
	return (1);
}

int	parse_heredoc(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if ((tmp->type == 7 || tmp->type == 4 || tmp->type == 5
				|| tmp->type == 6) && !tmp->next)
		{
			ft_putstr_fd("minishell: syntax error ", STDERR);
			ft_putendl_fd("near unexpected token `newline'", STDERR);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
