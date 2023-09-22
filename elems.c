/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:18:25 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 15:18:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(char *tab)
{
	if ((tab[0] == '<' && tab[1] != '<') || tab[0] == '>')
		return (7);
	return (0);
}

int	is_heredoc(char *tab)
{
	if (tab[0] == '<' && tab[1] == '<')
		return (8);
	return (0);
}

int	is_pipe(char *tab)
{
	if (tab[0] == '|')
		return (9);
	return (0);
}

int	is_char(char *tab)
{
	if (tab[0] == 34 || tab[0] == 39)
		return (10);
	return (0);
}

int	is_builtin(char *tab)
{
	if (built_cmp(tab))
		return (11);
	return (0);
}


// int	is_cmd(t_token *cmd, char *tab)
// {
// 	cmd->type = ft_strdup("cmd");
// 	cmd->elem = ft_strdup(tab);
// 	return (1);
// }

// int	is_heredoc(t_token *cmd, char *tab)
// {
// 	if (tab[0] == '<' && tab[1] == '<')
// 	{
// 		cmd->type = ft_strdup("heredoc");
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }

// int	is_redir(t_token *cmd, char *tab)
// {
// 	if ((tab[0] == '<' && tab[1] != '<') || tab[0] == '>')
// 	{
// 		cmd->type = ft_strdup("redir");
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }

// int	is_pipe(t_token *cmd, char *tab)
// {
// 	if (tab[0] == '|')
// 	{
// 		cmd->type = ft_strdup("pipe");
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }

// int	is_char(t_token *cmd, char *tab, char *str)
// {
// 	char	*res;

// 	if (tab[0] == 34 && tab[ft_strlen(tab) - 1] == 34)
// 	{
// 		cmd->type = ft_strdup(str);
// 		res = tronc_optn(tab);
// 		cmd->elem = ft_strdup(res);
// 		free(res);
// 		return (1);
// 	}
// 	else if (tab[0] == 39 && tab[ft_strlen(tab) - 1] == 39)
// 	{
// 		cmd->type = ft_strdup(str);
// 		res = tronc_optn(tab);
// 		cmd->elem = ft_strdup(res);
// 		free(res);
// 		return (1);
// 	}
// 	return (0);
// }
