/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:18:25 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 15:18:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_cmd(t_cmd *cmd, char *tab)
{
	char	*com;

	com = ft_strjoin("/usr/bin/", tab);
	if (access((const char *)com, F_OK | X_OK) == 0)
	{
		cmd->type = "cmd";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	is_option(t_cmd *cmd, char *tab)
{
	if (tab[0] == 45)
	{
		cmd->type = "option";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}


int	is_redir(t_cmd *cmd, char *tab)
{
	if (tab[0] == 60 || tab[0] == 62)
	{
		cmd->type = "redir";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	is_pipe(t_cmd *cmd, char *tab)
{
	if (tab[0] == '|')
	{
		cmd->type = "pipe";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	is_char(t_cmd *cmd, char *tab, char *str)
{
	if (tab[0] == 34)
	{
		if (tab[ft_strlen(tab) - 1] == 34)
		{
			cmd->type = str;
			cmd->elem = tronc_optn(tab);
			return (1);
		}
	}
	else if (tab[0] == 39)
	{
		if (tab[ft_strlen(tab) - 1] == 39)
		{
			cmd->type = str;
			cmd->elem = tronc_optn(tab);
			return (1);
		}
	}
	return (0);
}
