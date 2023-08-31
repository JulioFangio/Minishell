/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:36:26 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 14:36:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_split(t_cmd *cmd, char *tab)
{
	if (is_builtin(cmd, tab))
		return ;
	if (is_cmd(cmd, tab))
		return ;
	else if (is_option(cmd, tab))
		return ;
	else if (is_arg(cmd, tab))
		return ;
	else if (is_redir(cmd, tab))
		return ;
	else if (is_pipe(cmd, tab))
		return ;
	else if (is_char(cmd, tab, "string"))
		return ;
	else
	{
		cmd->type = "arg";
		cmd->elem = tab;
		return ;
	}
	return ;
}

t_cmd	*get_cmd(char **tab)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	int		i;

	cmd = make_cmd(tab);
	tmp = cmd;
	i = -1;
	while (tab[++i])
		printf("tab = %s\n", tab[i]);
	i = 0;
	while (tab[i])
	{
		parse_split(cmd, tab[i]);
		i++;
		cmd = cmd->next;
	}
	while (i > 0)
	{
		printf("type = %s et elem = %s\n", tmp->type, tmp->elem);
		tmp = tmp->next;
		i--;
	}
	return (tmp);
}
