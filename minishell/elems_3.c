/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:51:15 by juduval           #+#    #+#             */
/*   Updated: 2023/09/19 16:23:58 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_scenario(t_cmd *cmd, char *tab, int nb)
{
	if (nb == 1)
		fill_elem(cmd, tab, "list");
	else if (nb == 2)
		fill_elem(cmd, tab, "exp tilde");
	else if (nb == 3)
		fill_elem(cmd, tab, "arithmetic op");
	else if (nb == 4)
		fill_elem(cmd, tab, "substitution cmd");
	else if (nb == 5)
		fill_elem(cmd, tab, "variable");
	else if (nb == 6)
		fill_elem(cmd, tab, "filename");
	else if (nb == 7)
		fill_elem(cmd, tab, "redir");
	else
		exec_scenario_2(cmd, tab, nb);
}

void	exec_scenario_2(t_cmd *cmd, char *tab, int nb)
{
	if (nb == 8)
		fill_elem(cmd, tab, "heredoc");
	else if (nb == 9)
		fill_elem(cmd, tab, "pipe");
	else if (nb == 10)
		fill_elem_tronc(cmd, tab, "optn/arg");
	else if (nb == 11)
		fill_elem(cmd, tab, "builtin");
	else if (nb == 12)
		fill_elem(cmd, tab, "command");
	else if (nb == 13)
		fill_elem(cmd, tab, "optn/arg");
}

int	ft_optn(t_cmd *cmd, char *tab, int optn)
{
	if (optn == 7)
		fill_elem(cmd, tab, "name");
	else
		fill_elem(cmd, tab, "delimiter");
	return (0);
}
