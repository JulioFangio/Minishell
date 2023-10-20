/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:51:15 by juduval           #+#    #+#             */
/*   Updated: 2023/10/20 12:31:37 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_scenario(t_data *data, t_token *cmd, char *tab, int nb)
{
	if (nb == 5)
		fill_elem_var(data, cmd, tab, 15); //variable
	else if (nb == 7)
		fill_elem_redir(cmd, tab); //redir
	else if (nb == 8)
		fill_elem(cmd, tab, 7); //heredoc
	else if (nb == 9)
		fill_elem(cmd, tab, 3); //pipe
	// else if (nb == 10)
	// 	fill_elem_tronc(data, cmd, tab); //optn/arg
	else if (nb == 11)
		fill_elem(cmd, tab, 1); //builtin
	else if (nb == 12)
		fill_elem_tronc(data, cmd, tab, 1); //cmd
	else if (nb == 13)
		fill_elem_tronc(data, cmd, tab, 2); //optn/arg
}

int	ft_optn(t_token *cmd, char *tab, int optn)
{
	if (optn == 7)
		fill_elem(cmd, tab, 9); //name
	else if (optn == 8)
		fill_elem(cmd, tab, 8); //delimiter
	return (0);
}
