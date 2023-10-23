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

#include "../../includes/minishell.h"

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

int	is_a_builtin(char *tab)
{
	if (built_cmp(tab))
		return (11);
	return (0);
}
