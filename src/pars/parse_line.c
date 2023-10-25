/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:54:41 by juduval           #+#    #+#             */
/*   Updated: 2023/10/25 20:39:54 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_intruder(t_token *token, char c)
{
	int	i;

	i = -1;
	if (!token->str)
		return (1);
	while (token->str[++i] && token->type != 3)
	{
		if (token->str[i] == c)
		{
			if (c == '|')
			{
				ft_putstr_fd("minishell : ", STDERR);
				ft_putendl_fd("near unexpected token `|'", STDERR);
			}
			return (0);
		}
	}
	return (1);
}

int	parse_pipe(t_token *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->next && (cmd->type == 3 && cmd->next->type == 3))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'",
			STDERR);
		return (0);
	}
	else if (cmd->type == 3 && ft_strlen(cmd->str) == 1)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'",
			STDERR);
		return (0);
	}
	return (parse_pipe_while(cmd));
}

int	parse_pipe_while(t_token *cmd)
{
	t_token	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->type == 3 && (tmp->str[1] == '|' || !find_intruder(tmp, '<')
				|| !find_intruder(tmp, '>')))
		{
			ft_putendl_fd("minishell: syntax error near unexpected token `|'",
				STDERR);
			return (0);
		}
		else if (tmp->next && tmp->type == 3 && tmp->next->type == 3)
		{
			ft_putendl_fd("minishell: syntax error near unexpected token `|'",
				STDERR);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	parse_redir(t_token *cmd)
{
	char	c;

	if (ft_strlen(cmd->str) > 2 || (ft_strlen(cmd->str) > 2
			&& cmd->str[0] != cmd->str[1]))
	{
		c = cmd->str[0];
		print_err_msg(c);
		return (0);
	}
	else if (cmd->next && (is_redir(cmd->next->str)
			|| is_heredoc(cmd->next->str) || is_pipe(cmd->next->str)))
	{
		c = cmd->str[0];
		if (ft_strlen(cmd->str) < 2)
			print_err_msg(c);
		else
			print_err_msg(c);
		return (0);
	}
	return (1);
}

int	parse_line(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (!check_first_token_for_each_pipe(data))
		return (0);
	if (!parse_pipe(data->token))
		return (0);
	while (tmp)
	{
		if (tmp->type == 4 || tmp->type == 5 || tmp->type == 6
			|| tmp->type == 7)
		{
			if (!parse_redir(tmp))
				return (0);
		}
		tmp = tmp->next;
	}
	if (!parse_heredoc(data->token))
		return (0);
	return (1);
}
