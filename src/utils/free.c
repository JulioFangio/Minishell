/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:31:56 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/18 16:11:25 by juduval          ###   ########.fr       */
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
				ft_memdel(tab[i]);
			}
		}
		// ft_memdel(tab);
	}
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	printf("iciiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n");
	if (env)
	{
		while (env)
		{
			tmp = env->next;
			if (env->value && env)
			{
				printf("lolilolilolilolilo\n");
				ft_memdel(env->value);
			}
			// ft_memdel(env);
			env = tmp;
		}
	}
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
				ft_memdel(token->str);
			// ft_memdel(token);
			token = tmp;
		}
	}
}

void	free_and_close_data(t_data *data, int nb)
{
	// (void)nb;
	printf("Minishell program freeing in here %d\n", nb);
	if (data->token)
		free_token(data->token);
	// if (data->export)
	// 	free_env(data->export);
	if (data->tab)
		free_tab(data->tab);
}

void	free_env_unset(t_data *data, t_env *env)
{
	if (data->env == env && env->next == NULL)
	{
		ft_memdel(data->env->value);
		data->env->value = NULL;
		data->env->next = NULL;
		return ;
	}
	ft_memdel(env->value);
	ft_memdel(env);
}


// void	free_data(t_data *data)
// {
// 	while (data->env)
// 	{
// 		free(data->env->value);
// 		data->env = data->env->next;
// 	}
// 	//if (data->exprt)
// 	//{
// 	//	while (data->exprt)
// 	//	{
// 	//		free(data->exprt->value);
// 	//		data->exprt = data->exprt->next;
// 	//	}
// //	}
// 	// free(data->env);
// 	// free(data);
// }
