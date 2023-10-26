/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:45:27 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 13:01:32 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_size_env(t_env *env)
{
	int		size;
	t_env	*current;

	current = env;
	size = 0;
	while (current && current->next)
	{
		if (current->value)
			size += strlen(current->value);
		if (current->next->next)
			size++;
		current = current->next;
	}
	return (size);
}

/*
copies the values of environment variables stored in a linked list
into a string, adding a line feed between each value*/
char	*dup_env(t_env *env)
{
	int		size;
	char	*ptr_env;
	t_env	*current;
	int		i;

	size = get_size_env(env);
	i = 0;
	current = env;
	ptr_env = ft_calloc(sizeof(char), (size + 1));
	if (!ptr_env)
		return (NULL);
	current = env;
	while (current && current->next)
	{
		if (current->value)
		{
			ft_strcpy(ptr_env + i, current->value);
			i += ft_strlen(current->value);
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
