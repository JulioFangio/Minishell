/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:51:15 by juduval           #+#    #+#             */
/*   Updated: 2023/09/22 16:27:14 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_scenario(t_token *cmd, char *tab, int nb)
{
	if (nb == 1)
		fill_elem(cmd, tab, "list", 0);
	else if (nb == 2)
		fill_elem(cmd, tab, "exp tilde", 0);
	else if (nb == 3)
		fill_elem(cmd, tab, "arithmetic op", 0);
	else if (nb == 4)
		fill_elem(cmd, tab, "substitution cmd", 0);
	else if (nb == 5)
		fill_elem_var(cmd, tab, "variable", 0);
	else if (nb == 6)
		fill_elem(cmd, tab, "filename", 0);
	else if (nb == 7)
		fill_elem(cmd, tab, "redir", 4);
	else
		exec_scenario_2(cmd, tab, nb);
}

void	exec_scenario_2(t_token *cmd, char *tab, int nb)
{
	if (nb == 8)
		fill_elem(cmd, tab, "heredoc", 7);
	else if (nb == 9)
		fill_elem(cmd, tab, "pipe", 3);
	else if (nb == 10)
		fill_elem_tronc(cmd, tab, "optn/arg");
	else if (nb == 11)
		fill_elem(cmd, tab, "builtin", 1);
	else if (nb == 12)
		fill_elem(cmd, tab, "command", 1);
	else if (nb == 13)
		fill_elem(cmd, tab, "optn/arg", 2);
}

int	ft_optn(t_token *cmd, char *tab, int optn)
{
	if (optn == 7)
		fill_elem(cmd, tab, "name", 0);
	else
		fill_elem(cmd, tab, "delimiter", 0);
	return (0);
}

void	fill_elem_var(t_token *cmd, char *tab, char *str, int nb)
{
	//extern char	**environ;

	cmd->type = ft_strdup(str);
	cmd->elem = ft_strdup(tab);
	cmd->code = nb;
	return ;
}
