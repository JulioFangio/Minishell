/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:38:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 12:46:30 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalnum_exp(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_')
		return (1);
	else
		return (0);
}

int	ft_isalpha_exp(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| c == '_')
		return (1);
	else
		return (0);
}

int	is_exp_arg_valid(char *arg)
{
	int		i;
	int		check_eq;

	i = 0;
	check_eq = 0;
	while (arg[++i])
	{
		if (arg[i] == '=')
			check_eq = 1;
	}
	i = -1;
	while (arg[++i] && arg[i] != '=')
	{
		if (!ft_isalnum_exp(arg[i]))
		{
			return (0);
		}
	}
	if (check_eq == 1)
		return (1);
	return (0);
}

t_env	*ft_env_new(char *arg)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	new_env->value = ft_strdup(arg);
	new_env->next = NULL;
	return (new_env);
}

t_env	*ft_envlast(t_env *tmp)
{
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
