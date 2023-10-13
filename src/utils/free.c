/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:31:56 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/13 23:11:33 by juduval          ###   ########.fr       */
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
	tab = NULL;
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->value)
		{
			free(env->value);
			env->value = NULL;
		}
		free(env);
		env = tmp;
	}
}

void	free_token(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->next;
		if (token->str)
		{
			free(token->str);
			token->str = NULL;
		}
		free(token);
		token = tmp;
	}
}

void	free_and_close_data(t_data *data, int nb)
{
	if (data->fd_in != 0)
		close(data->fd_in);
	if (data->fd_out != 1)
		close(data->fd_out);
	ft_close_fd(data->in);
	ft_close_fd(data->out);
	ft_close_all_fd(data);
	// close(STDIN);
	// close(STDOUT);
	// close (STDERR);
	(void)nb;
	//printf("Minishell program freeing in here %d\n", nb);
	if (data->token)
		free_token(data->token);
	// if (data->env)
	// 	free_env(data->env);
	if (data->export)
		free_env(data->export);
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
