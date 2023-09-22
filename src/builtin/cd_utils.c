/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:59:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/12 18:05:10 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*search for a specific environment variable (var) in a chained list of env
 and extract its value*/
char	*get_path(t_env *env, char *var, size_t len)
{
	size_t	i;
	size_t	j;
	char	*old_pwd;
	int		size_oldpwd;

	while (env && env->next)
	{
		if (ft_strncmp(env->value, var, len) == 0)
		{
			size_oldpwd = ft_strlen(env);
			old_pwd = malloc(sizeof(char) * (size_oldpwd + 1));
			i = 0;
			j = 0;
			while (env->value[i++])
			{
				if (i > len)
					old_pwd[j++] = env->value[i];
			}
			old_pwd[j] = '\0';
			return (old_pwd);
		}
		env = env->next;
	}
	return (NULL);
}

/*retrieve the value of the "OLDPWD" environment variable
(which is generally used to store the previous directory,
the previous working directory) and store this value in the path variable*/
char	*get_oldpwd_path(char *path, t_env *env)
{
	path = get_path(env, "OLDPWD", 6);
	if (!path)
		ft_putendl_fd("The variable old_path is not defined", STDERR_FILENO);
	return (path);
}
