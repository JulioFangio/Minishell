/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/03 14:36:52 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* int	len_to_equal(char *env)
{
	int	i;

	i = 0;
	while (env && env[i] != '=')
		i++;
	return (i);
}

char	*strchr_minishell(const char *str, char c)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = 0;
	i = 0;
	if (!str || !c)
		return (NULL);
	while (str[len] != '\0' && str[len] != '=')
		len++;
	if (len == ft_strlen(str))
		return (NULL);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	comp_len(char *arg_to_cat, char *value)
{
	char	*cmp;

	cmp = strchr_minishell(arg_to_cat, '=');
	if (cmp == NULL)
		cmp = arg_to_cat;
	if (ft_strlen(cmp) == ft_strlen(value))
		return (0);
	else
		return (1);
}

int	unset_env(char **arg, t_data *data, int i)
{
	t_env	*env;
	t_env	*tmp;

	env = data->env;
	if (comp_len(env->value, arg[i]) == 0)
		&& ft_strncmp(arg[i], env->value, len_to_equal(env->value))
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
		unset_export(arg, data, i);
	}
	return (0);
}
 */