/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:54:41 by juduval           #+#    #+#             */
/*   Updated: 2023/10/13 16:58:13 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_intruder(t_token *token, char c)
{
	int	i;

	i = -1;
	if (!token->str)
		return (1);
	while (token->str[++i])
	{
		if (token->str[i] == c)
		{
			if (c == '|')
			{
				ft_putstr_fd("minishell: syntax error ", STDERR); 
				ft_putendl_fd("near unexpected token `|'", STDERR);
			}
			return (0);
		}
	}
	return (1);
}

int	parse_pipe(t_token *cmd)
{
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
		printf("minishell: syntax error near unexpected token lol`%c%c'\n", c, c);
		return (0);
	}
	else if (cmd->next && is_redir(cmd->next->str))
	{
		c = cmd->str[0];
		if (ft_strlen(cmd->str) < 2)
			printf("minishell: syntax error near unexpected token ok `%c'\n", c);
		else
			printf("minishell: syntax error near unexpected token pet `%c%c'\n",
				c, c);
		return (0);
	}
	return (1);
}
// ##

int	parse_line(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (!parse_pipe(data->token))
		return (0);
	else if (!parse_heredoc(data->token))
		return (0);
	else if (!parse_first_token(data->token))
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
	return (1);
}
// ## + parse_line_2.c parse heredoc


		// || ((is_redir(cmd->str) || is_heredoc(cmd->str))
		// 	&& (cmd->next && cmd->next->str[0] == '|')))