/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:38:47 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/11 18:42:56 by jaristil         ###   ########.fr       */
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

	ptr1_env = malloc(sizeof(t_env));
	if (!ptr1_env)
		return (ft_exit(ERR_MALLOC));
	ptr1_env->value = ft_strdup(env[0]);
	if (!ptr1_env->value)
		return (ft_exit(ERR_DUP));
	ptr1_env->next = NULL;
	data->env = ptr1_env;
	i = 1;
	while (env && env[i])
	{
		ptr2_env = malloc(sizeof(t_env));
		if (!ptr2_env)
			return (ft_exit(ERR_MALLOC));
		ptr2_env->value = ft_strdup(env[i++]);
		if (!ptr2_env->value)
			return (ft_exit(ERR_DUP));
		ptr2_env->next = NULL;
		ptr1_env->next = ptr2_env;
		ptr1_env = ptr2_env;
	}
}

/*create and initialize a new t_env structure
representing an environment variable to be exported.
It's used to manage exported env variables in a mini-shell context*/
t_env	*export_env(char *value)
{
	t_env	*export;

	export = malloc(sizeof(t_env));
	if (!export)
		return (ft_exit(ERR_MALLOC), NULL);
	if (value == NULL)
		export->value = NULL;
	else
	{
		export->value = ft_strdup(value);
		if (!export->value)
			return (ft_exit(ERR_DUP), NULL);
	}
	export->next = NULL;
	return (export);
}

/*replaces all non-ASCII characters in a line string with the '$' character
It returns a new modified string*/
char	*clean_env(char *to_find)
{
	char	*replace;
	int		i;

	replace = malloc(sizeof(char) + (ft_strlen(to_find) + 1));
	if (!replace)
		return (ft_exit(ERR_MALLOC), NULL);
	i = 0;
	while (to_find[i])
	{
		if (!ft_isascii(to_find[i]))
			replace[i] = '$';
		else
			replace[i] = to_find[i];
		i++;
	}
	replace[i] = '\0';
	free(to_find);
	return (replace);
}
