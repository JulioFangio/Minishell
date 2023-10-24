/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 13:07:44 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	delete_t_env(t_env *env, char *del)
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
			&& ft_strncmp(tmp->next->value, del, ft_strlen(del)) == 0)
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

static void	delete_first_env(t_data *data, char *narg)
{
	t_env	*tmp;

	tmp = data->env;
	data->env = data->env->next;
	free(tmp->value);
	free(narg);
	free(tmp);
}

static int	something_to_unset(t_data *data, char *arg)
{
	t_env	*tmp;
	char	*narg;
	int		i;

	i = 0;
	tmp = data->env;
	narg = ft_strjoin(arg, "=");
	while (tmp)
	{
		if (!ft_strncmp(tmp->value, narg, ft_strlen(narg)) && i == 0)
		{
			delete_first_env(data, narg);
			return (1);
		}
		else if (!ft_strncmp(tmp->value, narg, ft_strlen(narg)) && i > 0)
		{
			delete_t_env(data->env, narg);
			free(narg);
			return (1);
		}
		tmp = tmp->next;
		i++;
	}
	free(narg);
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
