/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:44:07 by juduval           #+#    #+#             */
/*   Updated: 2023/10/20 12:37:38 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_built(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	built_cmp(char *tab)
{
	const char	*cmp[] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit", "\0"};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (check_built(tab, cmp[i]))
			return (1);
		i++;
	}
	return (0);
}

int	scenario(char *tab, int check)
{
	// if (ext_dollar(tab))
	// 	return (5);
	if (is_redir(tab))
		return (7);
	else if (is_heredoc(tab))
		return (8);
	else if (is_pipe(tab))
		return (9);
	// else if (is_char(tab))
	// 	return (10);
	else if (check == 0 && is_a_builtin(tab))
		return (11);
	else if (check == 0)
		return (12);
	return (13);
}

// int	is_builtin(t_token *cmd, char *tab)
// {
// 	if (built_cmp(tab))
// 	{
// 		cmd->type = ft_strdup("builtin");
// 		cmd->elem = ft_strdup(tab);
// 		return (1);
// 	}
// 	return (0);
// }

