/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:49:58 by juduval           #+#    #+#             */
/*   Updated: 2023/10/25 20:34:15 by juduval          ###   ########.fr       */
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
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '/')
			return (0);
		i++;
	}
	return (1);
}

static int	check_for_usrbin(char *str, int i, int check_usr, int check_bin)
{
	while (str[i])
	{
		if (!strncmp(str + i, "usr", 3))
		{
			check_usr = 1;
			i += 3;
		}
		else if (!strncmp(str + i, "bin", 3))
		{
			check_bin = 1;
			i += 3;
		}
		i++;
	}
	if (check_usr == 1 && check_bin == 0)
		return (0);
	else if (check_usr == 0 && check_bin == 1)
		return (1);
	else if (check_usr == 1 && check_bin == 1)
		return (1);
	return (0);
}

int	parse_first_token(t_token *token)
{

	if (token && !token->next && (!ft_strcmp(token->str, "!")
			|| !ft_strcmp(token->str, ":")))
		return (0);
	else if (token && only_slash(token->str))
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(" : is a directory", STDERR);
		return (0);
	}
	else if (token && token->str && (token->str[0] == '/' && ((!token->str[1])
				|| token->str[1] == '.')))
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(" : is a directory", STDERR);
		return (0);
	}
	else if (token && token->str && token->str[0] == '/'
		&& !check_for_usrbin(token->str, 0, 0, 0))
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(" : no such file or directory", STDERR);
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