/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:44:07 by juduval           #+#    #+#             */
/*   Updated: 2023/09/05 19:37:53 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_built(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int	built_cmp(char *tab)
{
	const char	*cmp[] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit", "\0"};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (check_built(tab, cmp[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_builtin(t_cmd *cmd, char *tab)
{
	if (built_cmp(tab))
	{
		cmd->type = "builtin";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	is_esper(t_cmd *cmd, char *tab)
{
	if (tab[0] == '&')
	{
		cmd->type = "esper";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	is_arg(t_cmd *cmd, char *tab)
{
	int	i;

	i = 0;
	if (is_char(cmd, tab, "arg"))
		return (1);
	i += is_cmd(cmd, tab);
	i += is_option(cmd, tab);
	i += is_pipe(cmd, tab);
	i += is_redir(cmd, tab);
	i += is_esper(cmd, tab);
	if (i == 0)
	{
		cmd->type = "arg";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}
