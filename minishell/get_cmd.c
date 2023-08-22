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

void	parse_split(t_list *cmd, chqr *tab)
{
	
}

t_list   *get_cmd(t_list **tab)
{
    t_list *cmd;
	t_list *tmp;
	int		i;

	cmd = make_list(tab);
	tmp = cmd;
	i = 0;
	while (cmd->next && tab[i])
	{
    	parse_split(cmd, tab);
		i++
		cmd = cmd->next;
	}
	return(tmp);
}
