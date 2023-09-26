/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:54:41 by juduval           #+#    #+#             */
/*   Updated: 2023/09/25 18:13:39 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parse_redir(t_token *cmd)
{
	char	c;
	t_token	*tmp;

	tmp = cmd;
	if (ft_strlen(cmd->elem) > 2)
	{
		c = cmd->elem[0];
		printf("minishell: syntax error near unexpected token `%c%c'\n", c, c);
		return (0);
	}
	else if (is_redir(tmp->next->elem))
	{
		c = cmd->elem[0];
		if (ft_strlen(cmd->elem) < 2)
			printf("minishell: syntax error near unexpected token `%c'\n", c);
		else
			printf("minishell: syntax error near unexpected token `%c%c'\n",
				c, c);
		return (0);
	}
	return (1);
}

int	parse_line(t_token *cmd)
{
	while (cmd)
	{
		if (cmd->type == 4 || cmd->type == 5 || cmd->type == 6)
		{
			if (!parse_redir(cmd))
				return (0);
		}
		cmd = cmd->next;
	}
	return (1);
}
