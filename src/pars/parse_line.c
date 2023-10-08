/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:54:41 by juduval           #+#    #+#             */
/*   Updated: 2023/10/08 13:23:06 by jaristil         ###   ########.fr       */
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

int	check_line(char *line)
{
	if (!check_quotes(line))
	{
		printf("%s: syntax error\n", line);
		return (0);
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

int	parse_line(t_token *cmd, char **tab)
{
	(void)tab;
	while (cmd)
	{
		if (cmd->type == 4 || cmd->type == 5 || cmd->type == 6)
		{
			if (!parse_redir(cmd))
				return (0);
		}
		// check_heredoc(cmd, tab);
		cmd = cmd->next;
	}
	return (1);
}
