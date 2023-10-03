/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/03 17:31:50 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	len_to_equal(char *env)
{
	int	i;

	i = 0;
	while (env && env[i] != '=')
		i++;
	return (i);
}

/*finds the first occurrence of the '=' character in the str string
and returns a new string containing the portion
of str up to this '=' character*/
char	*ft_strchr_minishell(const char *str, char c)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!str || !c)
		return (NULL);
	while (str[len] && str[len] != '=')
		len++;
	if (len == ft_strlen(str))
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (ft_exit(ERR_MAL), NULL);
	while (i++ < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (ret);
}

int	comp_len_val(char *arg, char *value)
{
	char	*cmp;

	cmp = ft_strchr_minishell(arg, '=');
	if (cmp == NULL)
		cmp = arg;
	if (ft_strlen(cmp) == ft_strlen(value))
		return (SUCCESS);
		// 0
	else
		return (FAILURE);
		// 1
}

int	unset_env(char **arg, t_data *data, int i)
{
	t_env	*env;
	t_env	*tmp;

	env = data->env;
	if ((comp_len_val(env->value, arg[i]) == SUCCESS)
		&& ft_strncmp(arg[i], env->value, len_to_equal(env->value)))
	{
		if (env->next)
			data->env = env->next;
		free_env_unset(data, env->next);
		return (0);
	}
}

int	make_unset(char **arg, t_data *data)
{
	int	i;

	i = 1;
	if (!(arg[i]))
		return (0);
	while (arg[i++])
	{
		unset_env(arg, data, i);
		//unset_export(arg, data, i);
	}
	return (0);
}
