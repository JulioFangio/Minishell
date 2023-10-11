/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:41:07 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/11 14:51:10 by jaristil         ###   ########.fr       */
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

char	**token_cmd_to_tab(t_token *token)
{
	t_token	*token_ptr;
	char	**tab;
	int		i;

	if (!token)
		return (NULL);
	token_ptr = token->next;
	i = 2;
	while (token_ptr && token_ptr->type < PIPE)
	{
		token_ptr = token_ptr->next;
		i++;
	}
	tab = malloc(sizeof(char *) * (i));
	if (tab == NULL)
		return (ft_exit(ERR_MALLOC), NULL);
	token_ptr = token->next;
	tab[0] = ft_strdup(token->str);
	tab = token_to_tab(token_ptr, tab);
	return (tab);
}
