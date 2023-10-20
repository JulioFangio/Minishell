/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:49:58 by juduval           #+#    #+#             */
/*   Updated: 2023/10/20 12:04:19 by juduval          ###   ########.fr       */
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

int	parse_first_token(t_token *token)
{
	if (!token->next && (!ft_strcmp(token->str, "!")
			|| !ft_strcmp(token->str, ":")))
		return (0);
	else if (!token->next && token->str[0] == '/')
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
		if (!find_intruder(tmp, '|'))
			return (0);
		else if ((tmp->type == 7 || tmp->type == 4 || tmp->type == 5
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

int	parse_ls(t_data *data, int check_ls)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp && tmp->type != 3)
	{
		if (tmp->type == 1 && !ft_strcmp(tmp->str, "ls") && check_ls == 0)
		{
				check_ls = 1;
				tmp = data->token;
		}
		else if (tmp->type == 0 && check_ls == 1)
		{
			ft_putendl_fd("ls: cannot access '': No such file or directory",
				STDERR);
			return (0);
		}
		else if (tmp->str && tmp->str[0] != '-' && tmp->type == 2
			&& check_ls == 1)
		{
			ft_putstr_fd("ls: cannot access '", STDERR);
			ft_putstr_fd(tmp->str, STDERR);
			ft_putendl_fd("': No such file or directory", STDERR);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
