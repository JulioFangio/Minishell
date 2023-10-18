/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:47:52 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/18 15:58:31 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_isalnum_exp(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9') || c == '_')
		return (1);
	else
		return (0);
}

static int	ft_isalpha_exp(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| c == '_')
		return (1);
	else
		return (0);
}

static int	is_exp_arg_valid(char *arg)
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
			printf("not_alnum\n");
			return (0);
		}
	}
	if (check_eq == 1)
		return (1);
	printf("no =\n");
	return (0);
}

static t_env	*ft_envlast(t_env *tmp)
{
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_env	*ft_env_new(char *arg)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	new_env->value = ft_strdup(arg);
	new_env->next = (NULL);
	return (new_env);
}

void	ft_env_add_back(t_env **env, t_env *new)
{
	t_env	*last;
	t_env	**tmp;

	tmp = env;
	if (tmp)
	{
		if (*tmp)
		{
			last = ft_envlast(*tmp);
			last->next = new;
		}
		else
			*tmp = new;
	}
}

void	fill_env(t_data *data, t_env *env, char *arg)
{
	int		check;
	t_env	*tmp;

	check = 0;
	tmp = env;
	while (arg[check] && arg[check] != '=')
		check++;
	while (tmp)
	{
		if (!ft_strncmp(tmp->value, arg, check))
		{
			free(tmp->value);
			tmp->value = NULL;
			tmp->value = ft_strdup(arg);
			return ;
		}
		tmp = tmp->next;
	}
	ft_env_add_back(&data->env, ft_env_new(arg));
	return ;
}

int	make_export(t_data *data, char **cmd)
{
	int		i;
	int		check_err;

	i = 1;
	check_err = 1;
	while (cmd[i])
	{
		if (!cmd[i] || (cmd[i] && (!is_exp_arg_valid(cmd[1])
					|| !ft_isalpha_exp(cmd[i][0]))))
		{
			ft_putendl_fd("Error : wrong argument on export", STDERR);
			check_err = 0;
		}
		if (check_err != 0)
			fill_env(data, data->env, cmd[i]);
		i++;
	}
	if (check_err == 1)
		return (SUCCESS);
	return (FAILURE);
}
