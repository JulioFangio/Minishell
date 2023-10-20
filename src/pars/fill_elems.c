/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:42:04 by juduval           #+#    #+#             */
/*   Updated: 2023/10/20 12:32:40 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fill_elem(t_token *cmd, char *tab, int nb)
{
	cmd->str = ft_strdup(tab);
	cmd->type = nb;
	return ;
}

void	fill_elem_tronc(t_data *data, t_token *cmd, char *tab, int nb)
{
	char	*res;
	char	*tab_bis;

	tab_bis = NULL;
	res = NULL;
	if (tab[0] == '"' || tab[0] == '\'')
	{
		if (tab[0] == '"')
			res = ft_strdup(tronc_optn(data, tab, 1));
		else if (tab[0] == '\'')
			res = ft_strdup(tronc_optn(data, tab, 0));
		cmd->str = ft_strdup(res);
		free(res);
	}
	else
	{
		tab_bis = ft_strdup(tab);
		cmd->str = check_for_var(data, tab_bis, 1);
	}
	if (!cmd->str)
		cmd->type = 0;
	else
		cmd->type = nb;
	return ;
}

void	fill_elem_var(t_data *data, t_token *cmd, char *tab, int nb)
{
	char	*tab_bis;

	tab_bis = ft_strdup(tab);
	cmd->str = check_for_var(data, tab_bis, 1);
	cmd->type = nb;
	return ;
}

void	fill_elem_redir(t_token *cmd, char *tab)
{
	cmd->str = ft_strdup(tab);
	if (tab[0] == '>' && tab[1] == '>')
		cmd->type = 6;
	else if (tab[0] == '>')
		cmd->type = 4;
	else
		cmd->type = 5;
}
