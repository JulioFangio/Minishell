/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:45:27 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/22 20:39:43 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
copies the values of environment variables stored in a linked list
into a string, adding a line feed between each value*/
//char	*dup_env(char *ptr_env, t_env *env)
char	*dup_env(t_env *env)
{
	int		size;
	t_env	*current;
	char	*ptr_env;
	int		i;

	size = 0;
	i = 0;
	current = env;
	while (current && current->next)
	{
		if (current->value)
			size += strlen(current->value);
		if (current->next->next)
			size++;
		current = current->next;
	}
	ptr_env = ft_calloc(sizeof(char), (size + 1));
	if (!ptr_env)
		return (NULL);
	current = env;
	while (current && current->next)
	{
		if (current->value)
		{
			strcpy(ptr_env + i, current->value);
			i += strlen(current->value);
		}
		if (current->next->next)
			ptr_env[i++] = '\n';
		current = current->next;
	}
	return (ptr_env);
}

int	env_add_value_to_list(char *value, t_env *env)
{
	t_env	*new;
	t_env	*tmp;

	if (env && env->value == NULL)
	{
		env->value = ft_strdup(value);
		return (0);
	}
	new = malloc(sizeof(t_env));
	new->value = ft_strdup(value);
	while (env && env->next && env->next->next)
		env = env->next;
	tmp = env->next;
	env->next = new;
	new->next = tmp;
	return (SUCCESS);
}
