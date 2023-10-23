/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:48:15 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 14:48:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*ft_tokenlast(t_token *cmd)
{
	while (cmd && cmd->next)
		cmd = cmd->next;
	return (cmd);
}

void	ft_tokenadd_back(t_token **cmd, t_token *new)
{
	t_token	*last;

	if (cmd)
	{
		if (*cmd)
		{
			last = ft_tokenlast(*cmd);
			last->next = new;
		}
		else
			*cmd = new;
	}
}

t_token	*ft_tokennew(void)
{
	t_token	*elem;

	elem = malloc(sizeof(t_token));
	if (!(elem))
		return (NULL);
	elem->str = NULL;
	elem->type = 0;
	elem->next = (NULL);
	elem->prev = (NULL);
	return (elem);
}

t_token	*make_cmd(char **tab)
{
	t_token	*cmd;
	int		i;

	cmd = NULL;
	i = ft_lentab(tab);
	while (i > 0)
	{
		ft_tokenadd_back(&cmd, ft_tokennew());
		i--;
	}
	return (cmd);
}

int	ft_lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
