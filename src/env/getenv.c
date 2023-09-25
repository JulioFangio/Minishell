/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:56:57 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/25 17:39:02 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*is_valid 
checks if an env string is a valid environment variable by verifying
if it follows the naming conv for env variables
(starts with a letter or _ and contains only letters, numbers or _)*/
int	is_env(char *env)
{
	int	i;

	i = 0;
	if (isdigit(env[i]) == 1 || isalnum(env[i]) == 0)
		return (FAILURE);
	while (env[i] && env[i] != '=')
	{
		if (isalnum(env[i]) == 0 && env[i] != '\"')
			return (FAILURE);
		i++;
	}
	if (env[i] != '=')
		return (FAILURE);
	else
		return (SUCCESS);
}

/*env_val_len
calculates the length of an env variable's
value from the variable's complete string*/
int	len_var_env(char *env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (env[i] && env[i] != '=')
		i++;
	i += 1;
	while (env[i])
	{
		len++;
		i++;
	}
	return (len);
}

/*env_value
extracts the value of an environment variable
from the complete variable string*/
char	*extract_env_value(char *env)
{
	int		i;
	int		j;
	int		size;
	char	*env_value;

	i = 0;
	j = 0;
	size = len_var_env(env) + 1;
	env_value = malloc(sizeof(char) * size);
	if (env_value == NULL)
		return (ft_exit(ERR_MALLOC), NULL);
	while (env[i] && env[i] != '=')
		i++;
	i += 1;
	while (env[i])
		env_value[j++] = env[i++];
	env_value[j] = '\0';
	return (env_value);
}

/*
searches for the value of a specific env variable in the chained list 
of env variables (env) and returns this value*/
char	*get_env_value(char *arg, t_env *env)
{
	char	env_name_value[B_SIZE];
	char	*env_value;

	env_value = ft_strdup("");
	if (!env_value)
		return (ft_exit(ERR_DUP), NULL);
	while (env && env->value)
	{
		extract_name_env(env_name_value, env->value);
		if (ft_strcmp(env_name_value, env->value) == 0)
		{
			free(env_value);
			env_value = NULL;
			env_value = extract_env_value(env->value);
			return (env_value);
		}
		env = env->next;
	}
	return (env_value);
}

/*env_char
Checks whether a given character is allowed in the name of an env variable
Valid characters are alphanumeric and '_' */
int	config_env_char_name(int c)
{
	if (isalnum(c) == 1 || c == '_')
		return (1);
	return (0);
}
