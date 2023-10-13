/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:42:04 by juduval           #+#    #+#             */
/*   Updated: 2023/10/13 18:42:35 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fill_elem(t_token *cmd, char *tab, char *str, int nb)
{
	(void)str;
	cmd->str = ft_strdup(tab);
	cmd->type = nb;
	return ;
}

void	fill_elem_tronc(t_token *cmd, char *tab, char *str)
{
	char	*res;

	(void)str;
	if (tab[0] == '"')
		res = tronc_optn(tab, 1);
	else
		res = tronc_optn(tab, 0);
	cmd->str = ft_strdup(res);
	if (!cmd->str)
		cmd->type = 0;
	else
		cmd->type = 2;
	free(res);
	return ;
}

void	fill_elem_var(t_token *cmd, char *tab, char *str, int nb)
{
	char	*tab_bis;

	(void)str;
	tab_bis = ft_strdup(tab);
	cmd->str = check_for_var(tab_bis, 1);
	cmd->type = nb;
	return ;
}

void	fill_elem_redir(t_token *cmd, char *tab, char *str)
{
	(void)str;
	cmd->str = ft_strdup(tab);
	if (tab[0] == '>' && tab[1] == '>')
		cmd->type = 6;
	else if (tab[0] == '>')
		cmd->type = 4;
	else
		cmd->type = 5;
}
