/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:44:07 by juduval           #+#    #+#             */
/*   Updated: 2023/09/22 13:26:22 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	fill_elem(t_token *cmd, char *tab, char *str, int nb)
{
	cmd->type = ft_strdup(str);
	cmd->elem = ft_strdup(tab);
	cmd->code = nb;
	return ;
}

void	fill_elem_tronc(t_token *cmd, char *tab, char *str)
{
	char	*res;

	cmd->type = ft_strdup(str);
	res = tronc_optn(tab);
	cmd->elem = ft_strdup(res);
	cmd->code = 2;
	free(res);
	return ;
}

int	scenario(char *tab, int check)
{
	if (ext_bracers(tab))
		return (ext_bracers(tab));
	else if (ext_tilde(tab))
		return (ext_tilde(tab));
	else if (ext_dollar(tab))
		return (ext_dollar(tab));
	else if (ext_filename(tab))
		return (ext_filename(tab));
	else if (is_redir(tab))
		return (is_redir(tab));
	else if (is_heredoc(tab))
		return (is_heredoc(tab));
	else if (is_pipe(tab))
		return (is_pipe(tab));
	else if (is_char(tab))
		return (is_char(tab));
	else if (check == 0 && is_builtin(tab))
		return (is_builtin(tab));
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

