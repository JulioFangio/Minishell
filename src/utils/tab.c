/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <axlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:41:07 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/21 17:00:56 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	tab_size(char **tab)
{
	size_t	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

char	**token_to_tab(t_token *token, char **tab)
{
	int	i;

	i = 1;
	while (token && token->type < PIPE)
	{
		tab[i++] = ft_strdup(token->str);
		token = token->next;
	}
	tab[i] = NULL;
	return (tab);
}

static void	fill_others(t_token *token, char **tab)
{
	t_token	*tmp;
	int		i;

	i = 1;
	tmp = token;
	// while (tmp && tmp->type != PIPE)
	// {
	// 	if (tmp->str && tmp->str[0] == '-' && tmp->type == 2)
	// 	{
	// 		tab[i] = ft_strdup(tmp->str);
	// 		i++;
	// 	}
	// 	tmp = tmp->next;
	// }
	tmp = token;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->str && tmp->type == 2)
		{
			tab[i] = ft_strdup(tmp->str);
			i++;
		}
		tmp = tmp->next;
	}
}

static char	**fill_tctt(t_token *token, char **tab, int i)
{
	t_token	*tmp;

	tmp = token;
	tab = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (tmp || tmp->type != PIPE)
	{
		if (tmp->type == 1)
		{
			tab[i] = ft_strdup(tmp->str);
			break ;
		}
		tmp = tmp->next;
	}
	fill_others(token, tab);
	return (tab);
}

char	**token_cmd_to_tab(t_token *token)
{
	t_token	*tmp;
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	tmp = token;
	while (tmp && tmp->type != 3)
	{
		if (tmp->str && (tmp->type == 1 || tmp->type == 2))
			i++;
		tmp = tmp->next;
	}
	tab = fill_tctt(token, tab, i);
	return (tab);
}
