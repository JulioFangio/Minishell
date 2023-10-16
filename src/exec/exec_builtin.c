/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:40:34 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/14 23:29:20 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp("echo", cmd) == 0)
		return (1);
	else if (ft_strcmp("cd", cmd) == 0)
		return (1);
	else if (ft_strcmp("pwd", cmd) == 0)
		return (1);
	else if (ft_strcmp("export", cmd) == 0)
		return (1);
	else if (ft_strcmp("unset", cmd) == 0)
		return (1);
	else if (ft_strcmp("env", cmd) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_data *data, char **cmd, t_token *token)
{
	int	result;

	result = 0;
	(void) token;
	if (ft_strcmp("echo", cmd[0]) == 0)
		result = make_echo(data, cmd);
	if (ft_strcmp("cd", cmd[0]) == 0)
		result = make_cd(data, cmd, data->env);
	if (ft_strcmp("pwd", cmd[0]) == 0)
		result = make_pwd(data, data->env);
	if (ft_strcmp("export", cmd[0]) == 0)
	{
		if (!data->env)
			return (FAILURE);
		result = make_export(data, cmd);
	}
	if (ft_strcmp("unset", cmd[0]) == 0)
	{
		if (!data->env)
			return (FAILURE);
		result = make_unset(data, cmd);
	}
	if (ft_strcmp("env", cmd[0]) == 0)
		result = make_env(data, data->env);
	return (result);
}
