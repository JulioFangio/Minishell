/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:36:26 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 14:36:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*fill_list(t_token *cmd, char **tab, int i, int check)
{
	t_token		*tmp;
	int			res;
	int			optn;

	res = 0;
	optn = 0;
	tmp = cmd;
	while (cmd && tab[++i])
	{
		res = scenario(tab[i], check);
		if (!optn)
			exec_scenario(cmd, tab[i], res);
		else
			optn = ft_optn(cmd, tab[i], optn);
		if (res == 11 || res == 12)
			check = 1;
		else if (res == 9)
			check = 0;
		else if (res == 7 || res == 8)
			optn = res;
		cmd = cmd->next;
	}
	return (tmp);
}

t_token	*get_token(char **tab)
{
	t_token	*cmd;
	t_token	*tmp;

	cmd = make_cmd(tab);
	cmd = fill_list(cmd, tab, -1, 0);
	tmp = cmd;
	while (tmp)
	{
		printf(" type = %s / elem = %s / code = %d\n", tmp->type, tmp->elem, tmp->code);
		tmp = tmp->next;
	}
	return (cmd);
}

// t_token	*fill_list(t_token *cmd, char **tab)
// {
// 	int		i;
// 	t_token	*tmp;
// 	int		check;
// 	char	*res;

// 	tmp = cmd;
// 	i = 0;
// 	check = 0;
// 	res = NULL;
// 	while (tab[i])
// 	{
// 		if (is_exp(cmd, tab[i]) || is_elem(cmd, tab[i]))
// 		{
// 			if (!ft_strncmp("redir", cmd->type, 6))
// 			{
// 				cmd = cmd->next;
// 				cmd->type = ft_strdup("name");
// 				i++;
// 				cmd->elem = ft_strdup(tab[i]);
// 			}
// 			else if (!ft_strncmp("pipe", cmd->type, 5))
// 				check = 0;
// 			cmd = cmd->next;
// 			i++;
// 		}
// 		else
// 		{
// 			if (check == 0)
// 			{
// 				is_corb(cmd, tab[i]);
// 				i++;
// 				check = 1;
// 				cmd = cmd->next;
// 			}
// 			if (cmd && (!is_exp(cmd, tab[i]) && !is_elem(cmd, tab[i])))
// 			{
// 				cmd->type = ft_strdup("opt/arg");
// 				if (tab[i][0] == 34 || tab[i][0] == 39)
// 				{
// 					res = tronc_optn(tab[i]);
// 					cmd->elem = ft_strdup(res);
// 					free(res);
// 				}
// 				else
// 					cmd->elem = ft_strdup(tab[i]);
// 				i++;
// 				cmd = cmd->next;
// 			}
// 		}
// 	}
// 	return (tmp);
// }

// int	is_exp(t_token *cmd, char *tab)
// {
// 	if (ext_bracers(cmd, tab))
// 		return (1);
// 	else if (ext_tilde(cmd, tab))
// 		return (1);
// 	else if (dollar(cmd, tab))
// 		return (1);
// 	else if (ext_filename(cmd, tab))
// 		return (1);
// 	return (0);
// }

// int	is_corb(t_token *cmd, char *tab)
// {
// 	if (is_builtin(cmd, tab))
// 		return (2);
// 	else if (is_cmd(cmd, tab))
// 		return (2);
// 	return (0);
// }

// int	is_elem(t_token *cmd, char *tab)
// {
// 	if (is_redir(cmd, tab))
// 		return (4);
// 	else if (is_pipe(cmd, tab))
// 		return (5);
// 	// else if (is_char(cmd, tab, "opt/arg"))
// 	// 	return (1);
// 	return (0);
// }

