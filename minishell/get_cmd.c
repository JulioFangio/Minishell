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

int	parse_split(t_cmd *cmd, char *tab, int check)
{
	if (check == 0 && is_cmd(cmd, tab))
		return (1);
	else if (check == 1 && is_option(cmd, tab))
		return (1);
	else if (check == 1 && is_arg(cmd, tab))
		return (0);
	else if (is_redir(cmd, tab))
		return (0);
	else if (is_pipe(cmd, tab))
		return (0);
	else if (is_char(cmd, tab, "string"))
		return (0);
	else
	{
		cmd->type = "arg";
		cmd->elem = tab;
		return (0);
	}
	return (0);
}

t_cmd	*get_cmd(char **tab)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	int		i;
	int		check;

	cmd = make_cmd(tab);
	tmp = cmd;
	i = 0;
	check = 0;
	while (cmd->next && tab[i])
	{
		check = parse_split(cmd, tab[i], check);
		i++;
		cmd = cmd->next;
	}
	while (tmp->next)
	{
		printf("type = %s et elem = %s\n", tmp->type, tmp->elem);
		tmp = tmp->next;
	}
	return (tmp);
}
