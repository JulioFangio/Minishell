/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:51:15 by juduval           #+#    #+#             */
/*   Updated: 2023/10/13 16:04:47 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_scenario(t_token *cmd, char *tab, int nb)
{
	if (nb == 5)
		fill_elem_var(cmd, tab, "variable", 15);
	else if (nb == 7)
		fill_elem_redir(cmd, tab, "redir");
	else if (nb == 8)
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
	else if (optn == 8)
		fill_elem(cmd, tab, "delimiter", 8);
	return (0);
}

// char	*recup_env()
// "coucou >>ca va"