/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:31:56 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/08 13:12:27 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}			
	}
	free(tab);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->value);
		free(tmp);
	}
}

void	*free_token(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token;
		token = token->next;
		free(tmp->str);
		free(tmp);
	}
	return (NULL);
}

void	free_and_close_data(t_data *data)
{
	ft_close_fd(data->in);
	ft_close_fd(data->out);
	ft_close_all_fd(data);
	//close(STDIN);
	//close(STDOUT);
	if (data->token)
		data->token = free_token(data->token);
	if (data->env)
		free_env(data->env);
	if (data->export)
		free_env(data->export);
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


void	free_data(t_data *data)
{
	while (data->env)
	{
		free(data->env->value);
		data->env = data->env->next;
	}
	//if (data->exprt)
	//{
	//	while (data->exprt)
	//	{
	//		free(data->exprt->value);
	//		data->exprt = data->exprt->next;
	//	}
//	}
	// free(data->env);
	// free(data);
}
