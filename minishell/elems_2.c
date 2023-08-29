/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:44:07 by juduval           #+#    #+#             */
/*   Updated: 2023/08/29 17:11:13 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (i == 0)
	{
		cmd->type = "arg";
		cmd->elem = tab;
		return (1);
	}
	return (0);
}
