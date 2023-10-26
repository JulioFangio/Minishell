/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:31:56 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/26 16:34:48 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tab(char **tab)
{
	int		i;

	i = -1;
	if (tab)
	{
		while (tab[++i] && tab)
		{
			if (tab[i])
			{
				tab[i] = ft_memdel(tab[i]);
			}
		}
		tab = ft_memdel(tab);
	}
}

void	free_env(t_env **env_big)
{
	t_env	*tmp;
	t_env	*env;

	env = *env_big;
	if (env)
	{
		while (env)
		{
			tmp = env->next;
			if (env->value && env)
			{
				env->value = ft_memdel(env->value);
			}
			env = ft_memdel(env);
			env = tmp;
		}
	}
	*env_big = NULL;
}

void	free_token(t_token *token)
{
	t_token	*tmp;

	if (token)
	{
		while (token)
		{
			tmp = token->next;
			if (token->str && token)
			{
				token->str = ft_memdel(token->str);
			}
			token = ft_memdel(token);
			token = tmp;
		}
	}
}

// printf("Minishell program freeing in here %d\n", nb);
void	free_and_close_data(t_data *data)
{
	if (data->token)
	{
		free_token(data->token);
		data->token = NULL;
	}
}

void	free_tronc(t_tronc *tronc)
{
	t_tronc	*tmp;

	while (tronc)
	{
		tmp = tronc->next;
		if (!tronc->str)
		{
			tronc->str = ft_memdel(tronc->str);
		}
		tronc = ft_memdel(tronc);
		tronc = tmp;
	}
}
