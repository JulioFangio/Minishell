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

int	parse_split_2(t_cmd *cmd, char *tab)
{
	if (ext_bracers(cmd, tab))
		return (1);
	else if (ext_tilde(cmd, tab))
		return (1);
	else if (dollar(cmd, tab))
		return (1);
	else if (ext_filename(cmd, tab))
		return (1);
	return (0);
}

int	parse_split(t_cmd *cmd, char *tab, int check)
{
	if (is_builtin(cmd, tab))
		return (1);
	if (is_cmd(cmd, tab))
		return (1);
	else if (is_option(cmd, tab))
		return (1);
	else if (check == 1 && is_arg(cmd, tab))
		return (0);
	else if (is_redir(cmd, tab))
		return (0);
	else if (parse_split_2(cmd, tab))
		return (0);
	else if (is_pipe(cmd, tab))
		return (0);
	else if (is_esper(cmd, tab))
		return (0);
	else if (is_char(cmd, tab, "string"))
		return (0);
	else
	{
		cmd->type = "other";
		cmd->elem = tronc_optn(tab);
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

	check = 0;
	cmd = make_cmd(tab);
	tmp = cmd;
	i = 0;
	while (tab[i])
	{
		check = parse_split(cmd, tab[i], check);
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
