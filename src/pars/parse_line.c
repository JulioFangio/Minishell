/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:54:41 by juduval           #+#    #+#             */
/*   Updated: 2023/10/11 19:45:22 by jaristil         ###   ########.fr       */
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
			// else if (line[i + 1] != '\0' && (line[i + 1] != 32 ||
			// 		(line[i + 1] < 9 && line[i + 1] > 13)))
			// 	return (0);
			c = '\0';
		}
		i++;
	}
	if (c != '\0')
		return (0);
	return (1);
}

int	parse_pipe(t_token *cmd)
{
	if (cmd->next && cmd->type == 3 && cmd->next->type == 3)
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `||'",
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
		if (tmp->type == 3 && tmp->str[1] == '|')
		{
			ft_putendl_fd("minishell: syntax error near unexpected token `||'",
				STDERR);
			return (0);
		}
		else if (tmp->next && tmp->type == 3 && tmp->next->type == 3)
		{
			ft_putendl_fd("minishell: syntax error near unexpected token `||'",
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
	t_token	*tmp;

	tmp = cmd;
	if (ft_strlen(cmd->str) > 2)
	{
		c = cmd->str[0];
		printf("minishell: syntax error near unexpected token `%c%c'\n", c, c);
		return (0);
	}
	else if (tmp->next && is_redir(tmp->next->str))
	{
		c = cmd->str[0];
		if (ft_strlen(cmd->str) < 2)
			printf("minishell: syntax error near unexpected token `%c'\n", c);
		else
			printf("minishell: syntax error near unexpected token `%c%c'\n",
				c, c);
		return (0);
	}
	return (1);
}

int	parse_line(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (!parse_pipe(data->token))
		return (0);
	while (tmp)
	{
		if (tmp->type == 4 || tmp->type == 5 || tmp->type == 6)
		{
			if (!parse_redir(tmp))
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
