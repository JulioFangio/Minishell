/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/22 19:36:00 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	delete_t_env(t_env *env, char *del, int check)
{
	t_env	*tmp;
	t_env	*incr;
	t_env	*incr2;

	tmp = env;
	incr = NULL;
	incr2 = NULL;
	while (tmp)
	{
		if (tmp->next && tmp->next->value
			&& ft_strncmp(tmp->next->value, del, check) == 0)
		{
			if (tmp->next->next)
				incr = tmp->next->next;
			incr2 = tmp->next;
			if (incr2->value)
			{
				free(incr2->value);
				incr2->value = NULL;
			}
			free(incr2);
			tmp->next = incr;
		}
		tmp = tmp->next;
	}
}

static int	something_to_unset(t_data *data, char *arg)
{
	int		check;
	t_env	*tmp;

	check = 0;
	tmp = data->env;
	while (arg[check] && arg[check] != '=')
		check++;
	while (tmp)
	{
		if (!ft_strncmp(tmp->value, arg, check))
		{
			delete_t_env(data->env, tmp->value, check);
			return (1);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	make_unset(t_data *data, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (!cmd[i] || !something_to_unset(data, cmd[i]))
			return (1);
		i++;
	}
	return (1);
}
