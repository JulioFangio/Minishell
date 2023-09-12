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

int	is_exp(t_cmd *cmd, char *tab)
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

int	is_corb(t_cmd *cmd, char *tab)
{
	if (is_builtin(cmd, tab))
		return (1);
	else if (is_cmd(cmd, tab))
		return (1);
	// else if (is_option(cmd, tab))
	// 	return (1);
	// else if (check == 1 && is_arg(cmd, tab))
	return (0);
}

int	is_elem(t_cmd *cmd, char *tab)
{
	if (is_redir(cmd, tab))
		return (1);
	else if (is_pipe(cmd, tab))
		return (1);
	else if (is_char(cmd, tab, "string"))
		return (1);
	// else if (is_esper(cmd, tab))
	// 	return (1);
	// else
	// {
	// 	cmd->type = "other";
	// 	cmd->elem = tronc_optn(tab);
	// 	return (1);
	// }
	return (0);
}

t_cmd	*fill_list(t_cmd *cmd, char **tab)
{
	int		i;
	t_cmd	*tmp;

	tmp = cmd;
	i = 0;
	while (tab[i])
	{
		if (is_exp(cmd, tab[i]) || is_elem(cmd, tab[i]))
		{
			if (!ft_strncmp("redir", cmd->type, 5))
			{
				cmd = cmd->next;
				cmd->type = "name";
				i++;
				cmd->elem = tab[i];
			}
			cmd = cmd->next;
			i++;
		}
		else
		{
			is_corb(cmd, tab[i]);
			i++;
			cmd = cmd->next;
			while (cmd->next && (!is_exp(cmd, tab[i]) && !is_elem(cmd, tab[i])))
			{
				cmd->type = "opt/arg";
				cmd->elem = tab[i];
				i++;
				cmd = cmd->next;
			}
		}
	}
	return (tmp);
}

t_cmd	*get_cmd(char **tab)
{
	t_cmd	*cmd;
	t_cmd	*tmp;

	cmd = make_cmd(tab);
	tmp = fill_list(cmd, tab);
	while (tmp->next)
	{
		printf("type = %s et elem = %s\n", tmp->type, tmp->elem);
		tmp = tmp->next;
	}
	return (tmp);
}
