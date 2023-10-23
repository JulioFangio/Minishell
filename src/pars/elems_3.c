/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:51:15 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:21:00 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_scenario(t_data *data, t_token *cmd, char *tab, int nb)
{
	if (nb == 7)
		fill_elem_redir(cmd, tab);
	else if (nb == 8)
		fill_elem(cmd, tab, 7);
	else if (nb == 9)
		fill_elem(cmd, tab, 3);
	else if (nb == 11)
		fill_elem(cmd, tab, 1);
	else if (nb == 12)
		fill_elem_tronc(data, cmd, tab, 1);
	else if (nb == 13)
		fill_elem_tronc(data, cmd, tab, 2);
}

int	ft_optn(t_token *cmd, char *tab, int optn)
{
	if (optn == 7)
		fill_elem(cmd, tab, 9);
	else if (optn == 8)
		fill_elem(cmd, tab, 8);
	return (0);
}
