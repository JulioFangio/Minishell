/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:07:43 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 18:07:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ext_bracers(t_cmd *cmd, char *tab)
{
	if (tab[0] == '{')
	{
		cmd->type = "list";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	ext_tilde(t_cmd *cmd, char *tab)
{
	if (tab[0] == '~')
	{
		cmd->type = "exp tilde";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	dollar(t_cmd *cmd, char *tab)
{
	if (tab[0] == '$' && tab[1] == '(' && tab[2] == '(')
	{
		cmd->type = "arithmetic op";
		cmd->elem = tab;
		return (1);
	}
	else if (tab[0] == '$' && tab[1] == '(')
	{
		cmd->type = "substitution cmd";
		cmd->elem = tab;
		return (1);
	}
	else if (tab[0] == '$')
	{
		cmd->type = "variable";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}

int	ext_filename(t_cmd *cmd, char *tab)
{
	if (tab[0] == '*' || tab[0] == '?')
	{
		cmd->type = "filename";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}
