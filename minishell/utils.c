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

#include "minishell.h"

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	while (cmd && cmd->next)
		cmd = cmd->next;
	return (cmd);
}

void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (cmd)
	{
		if (*cmd)
		{
			last = ft_cmdlast(*cmd);
			last->next = new;
		}
		else
			*cmd = new;
	}
}

t_cmd	*ft_cmdnew(void)
{
	t_cmd	*elem;

	elem = malloc(sizeof(t_cmd));
	if (!(elem))
		return (NULL);
	elem->type = NULL;
	elem->elem = NULL;
	elem->next = (NULL);
	return (elem);
}

int	ft_lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_cmd	*make_cmd(char **tab)
{
	t_cmd	*cmd;
	int		i;

	cmd = NULL;
	i = ft_lentab(tab);
	while (i > 0)
	{
		ft_cmdadd_back(&cmd, ft_cmdnew());
		i--;
	}
	return (cmd);
}

// void	is_name(t_cmd *cmd, char *tab)
// {
// 	cmd->type = ft_strdup("name");
// 	cmd->elem = ft_strdup(tab);
// 	return ;
// }

// t_cmd	*make_cmd(char **tab)
// {
// 	t_cmd	*cmd;
// 	int		i;
// 	int		check;
// 	int		opt;

// 	cmd = NULL;
// 	i = 0;
// 	check = 0;
// 	opt = 0;
// 	while (tab[i])
// 	{
// 		ft_cmdadd_back(&cmd, ft_cmdnew());
// 		if (check == 3)
// 			is_name(cmd, tab[i]);

// 		check = (is_exp(cmd, tab[i]) + is_elem(cmd, tab[i])
// 				+ is_corb(cmd, tab[i]));
// 		if (check == 0)
// 		{

// 		}
// 		i++;
// 	}
// 	return (cmd);
// }


// refaire les fonctions is_smthing pour qu ils ne deviennent que des boulen, puis creer
// une fonction pour renplir l elem de la liste chainee en fonctions de la str passee
// en param ex "name", "pipe" etc.