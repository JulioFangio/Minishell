/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:07:43 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 18:07:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ext_bracers(char *tab)
{
	if (tab[0] == '{')
		return (1);
	return (0);
}

int	ext_tilde(char *tab)
{
	if (tab[0] == '~')
		return (2);
	return (0);
}

int	ext_dollar(char *tab)
{
	if (tab[0] == '$' && tab[1] == '(' && tab[2] == '(')
		return (3);
	else if (tab[0] == '$' && tab[1] == '(')
		return (4);
	else if (tab[0] == '$')
		return (5);
	return (0);
}

int	ext_filename(char *tab)
{
	if (tab[0] == '*' || tab[0] == '?')
		return (6);
	return (0);
}

// int	ext_bracers(t_token *cmd, char *tab)
// {
// 	if (tab[0] == '{')
// 	{
// 		cmd->type = "list";
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }

// int	ext_tilde(t_token *cmd, char *tab)
// {
// 	if (tab[0] == '~')
// 	{
// 		cmd->type = "exp tilde";
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }

// int	dollar(t_token *cmd, char *tab)
// {
// 	if (tab[0] == '$' && tab[1] == '(' && tab[2] == '(')
// 	{
// 		cmd->type = "arithmetic op";
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	else if (tab[0] == '$' && tab[1] == '(')
// 	{
// 		cmd->type = "substitution cmd";
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	else if (tab[0] == '$')
// 	{
// 		cmd->type = "variable";
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }

// int	ext_filename(t_token *cmd, char *tab)
// {
// 	if (tab[0] == '*' || tab[0] == '?')
// 	{
// 		cmd->type = "filename";
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }