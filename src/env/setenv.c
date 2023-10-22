/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:38:47 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/22 20:35:45 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*calculates the total len of the string in
the environment variables stored in a linked list*/
size_t	env_len(t_env *env)
{
	size_t	len;

	len = 0;
	while (env && env->next)
	{
		if (env->value)
		{
			len = ft_strlen(env->value);
			len += 1;
		}
		env = env->next;
	}
	return (len);
}

/*allocates memory for a string containing
all environment variables as a single character string*/

// eventually supress it and just call for the other fct
char	*env_malloc(t_env *env)
{
	char	*ptr_env;

	ptr_env = NULL;
	ptr_env = dup_env(env);
	return (ptr_env);
}

/*set all environment variables from the env array,
allowing mini-shell to access and manage
these env variables for command execution*/
void	set_env(t_data *data, char **env)
{
	t_env	*ptr1_env;
	t_env	*ptr2_env;
	int		i;

	if (!env)
	{
		data->env = NULL;
		return ;
	}
	ptr1_env = malloc(sizeof(t_env));
	if (!ptr1_env)
		return (ft_exit(ERR_MALLOC));
	ptr1_env->value = ft_strdup(env[0]);
	if (!ptr1_env->value)
		return (free(ptr1_env), ft_exit(ERR_DUP));
	ptr1_env->next = NULL;
	data->env = ptr1_env;
	i = 1;
	while (env && env[i])
	{
		ptr2_env = malloc(sizeof(t_env));
		if (!ptr2_env)
			return (free_env(&data->env), ft_exit(ERR_MALLOC));
		ptr2_env->value = ft_strdup(env[i++]);
		if (!ptr2_env->value)
			return (free_env(&data->env), free(ptr2_env), ft_exit(ERR_DUP));
		ptr2_env->next = NULL;
		ptr1_env->next = ptr2_env;
		ptr1_env = ptr2_env;
	}
}
