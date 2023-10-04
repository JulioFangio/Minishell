/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/04 16:21:53 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



/*scans the chained list of environment variables and deletes
the environment variable specified by args[nb] if found*/
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
	while (env && env->next)
	{
		if ((comp_len_val(env->next->value, arg[i]) == SUCCESS)
			&& !ft_strncmp(arg[i], env->next->value, len_to_equal(env->next->value)))
		{
			tmp = env->next->next;
			free_env_unset(data, env->next);
			env->next = tmp;
			return (0);
		}
		env = env->next;
	}
	return (0);
}

int	unset_export(char **arg, t_data *data, int i)
{
	t_env	*export;
	int		result;

	export = data->export;
	if (!(arg[i]) || export->value == NULL)
		return (1);
	result = remove_export(data, arg, i);
	return (result);
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
