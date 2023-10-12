/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:41:07 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/12 21:02:50 by juduval          ###   ########.fr       */
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

// char	**token_cmd_to_tab(t_token *token)
// {
// 	t_token	*token_ptr;
// 	char	**tab;
// 	int		i;

// 	if (!token)
// 		return (NULL);
// 	token_ptr = token->next;
// 	i = 2;
// 	while (token_ptr && token_ptr->type < PIPE)
// 	{
// 		token_ptr = token_ptr->next;
// 		i++;
// 	}
// 	tab = malloc(sizeof(char *) * (i));
// 	if (tab == NULL)
// 		return (ft_exit(ERR_MALLOC), NULL);
// 	token_ptr = token->next;
// 	tab[0] = ft_strdup(token->str);
// 	tab = token_to_tab(token_ptr, tab);
// 	return (tab);
// }

static char	**fill_tctt(t_token *token, char **tab, int i)
{
	t_token	*tmp;

	tmp = token;
	tab = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == 1)
		{
			tab[i] = ft_strdup(tmp->str);
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp && tmp->type != PIPE)
	{
		tab[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
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
		if (tmp->type == 0 || tmp->type == 1 || tmp->type == 2)
			i++;
		tmp = tmp->next;
	}
	printf("i = %d\n", i);
	tmp = token;
	tab = fill_tctt(token, tab, i);
	i = -1;
	while (tab[++i])
		printf("cmd %d = %s\n", i, tab[i]);
	return (tab);
}

	// while (tmp && tmp->type != PIPE)
	// {
	// 	if (tmp->type == 0 || tmp->type == 2)
	// 	{
	// 		tab[i] = ft_strdup(tmp->str);
	// 		i++;
	// 	}
	// 	tmp = tmp->next;
	// }