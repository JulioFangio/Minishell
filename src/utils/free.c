/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:31:56 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/21 21:04:00 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// static	int	len_tokens(t_token *token)
// {
// 	int		len;
// 	t_token	*tmp;

// 	len = 1;
// 	tmp = token;
// 	while (tmp)
// 	{
// 		len++;
// 		tmp = tmp->next;
// 	}
// 	return (len);
// }

// void	free_tab_2(char **tab, t_token *token)
// {
// 	int		i;
// 	// int		len
// 	t_token	*tmp;

// 	// len = len_tokens(token);
// 	i = 0;
// 	tmp = token;
// 	while (tmp)
// 	{
// 		if (tab[i])
// 		{
// 			tab[i] = ft_memdel(tab[i]);
// 		}
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	tab = ft_memdel(tab);
// }

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

void	free_and_close_data(t_data *data, int nb)
{
	// (void)nb;
	printf("Minishell program freeing in here %d\n", nb);
	if (data->tab)
	{
		free_tab(data->tab);
		data->tab = NULL;		
	}
	if (data->token)
	{
		free_token(data->token);
		data->token = NULL;
	}
}

