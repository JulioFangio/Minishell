/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:42:04 by juduval           #+#    #+#             */
/*   Updated: 2023/10/22 16:05:03 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fill_elem(t_token *cmd, char *tab, int nb)
{
	cmd->str = ft_strdup(tab);
	cmd->type = nb;
	return ;
}

// static int	is_there_a_quote(char *str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 	{
// 		if(str[i] == '"' || str[i] == '\'')
// 			return (1);
// 	}
// 	return (0);
// }

void	fill_elem_tronc(t_data *data, t_token *cmd, char *tab, int nb)
{
	char	*tab_bis;

	tab_bis = NULL;
	cmd->str = tronc_optn(data, tab, 1);
	cmd->type = nb;
	return ;
}

void	fill_elem_var(t_data *data, t_token *cmd, char *tab, int nb)
{
	char	*tab_bis;

	tab_bis = ft_strdup(tab);
	cmd->str = check_for_var(data, tab, 1);
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
