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

static void	fill_it(t_token *token, char **tab, int check, int optn)
{
	int	i;
	int	res;

	i = -1;
	while (token && tab[++i])
	{
		res = 0;
		if (!optn)
		{
			res = scenario(tab[i], check);
			exec_scenario(token, tab[i], res);
		}
		else
			optn = ft_optn(token, tab[i], optn);
		if (res == 11 || res == 12)
			check = 1;
		else if (res == 9)
			check = 0;
		else if (res == 7 || res == 8)
			optn = res;
		token = token->next;
	}
}

t_token	*fill_list(t_token *cmd, char **tab, int check)
{
	t_token		*tmp;
	int			optn;

	optn = 0;
	tmp = cmd;
	fill_it(tmp, tab, check, optn);
	return (cmd);
}
// ## + prototype

t_token	*get_token(char **tab)
{
	t_token	*cmd;
	t_token	*tmp;

	cmd = make_cmd(tab);
	cmd = fill_list(cmd, tab, 0);
	tmp = cmd;
	while (tmp)
	{
		printf(" str = %s / type = %d\n", tmp->str, tmp->type);
		tmp = tmp->next;
	}
	return (cmd);
}
// ##