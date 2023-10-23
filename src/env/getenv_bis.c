/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:48:01 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/22 20:37:24 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*in_env*/
/*extract the name of an environment variable
from a src string and store this name in dest*/
char	*extract_name_env(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '=' && ft_strlen(src) < B_SIZE \
	&& src[i] != ' ')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	update_env(char *arg, t_env *env)
{
	char	var_name[B_SIZE];
	char	env_name_value[B_SIZE];

	extract_name_env(var_name, arg);
	while (env && env->next)
	{
		extract_name_env(env_name_value, env->value);
		if (ft_strcmp(var_name, env_name_value) == 0)
		{
			if (is_env(arg) != 1)
				return (1);
			free(env->value);
			env->value = NULL;
			env->value = ft_strdup(arg);
			return (1);
		}
		env = env->next;
	}
	return (0);
}
