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
		return (2);
	else if (is_cmd(cmd, tab))
		return (2);
	return (0);
}

int	is_elem(t_cmd *cmd, char *tab)
{
	if (is_redir(cmd, tab))
		return (4);
	else if (is_pipe(cmd, tab))
		return (5);
	// else if (is_char(cmd, tab, "opt/arg"))
	// 	return (1);
	return (0);
}

t_cmd	*fill_list(t_cmd *cmd, char **tab)
{
	int		i;
	t_cmd	*tmp;
	int		check;
	char	*res;

	tmp = cmd;
	i = 0;
	check = 0;
	res = NULL;
	while (tab[i])
	{
		if (is_exp(cmd, tab[i]) || is_elem(cmd, tab[i]))
		{
			if (!ft_strncmp("redir", cmd->type, 6))
			{
				cmd = cmd->next;
				cmd->type = ft_strdup("name");
				i++;
				cmd->elem = ft_strdup(tab[i]);
			}
			else if (!ft_strncmp("pipe", cmd->type, 5))
				check = 0;
			cmd = cmd->next;
			i++;
		}
		else
		{
			if (check == 0)
			{
				is_corb(cmd, tab[i]);
				i++;
				check = 1;
				cmd = cmd->next;
			}
			if (cmd && (!is_exp(cmd, tab[i]) && !is_elem(cmd, tab[i])))
			{
				cmd->type = ft_strdup("opt/arg");
				if (tab[i][0] == 34 || tab[i][0] == 39)
				{
					res = tronc_optn(tab[i]);
					cmd->elem = ft_strdup(res);
					free(res);
				}
				else
					cmd->elem = ft_strdup(tab[i]);
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
	cmd = fill_list(cmd, tab);
	tmp = cmd;
	while (tmp)
	{
		printf(" type = %s et elem = %s\n", tmp->type, tmp->elem);
		tmp = tmp->next;
	}
	return (cmd);
}
