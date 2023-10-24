/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:40:34 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 20:27:28 by juduval          ###   ########.fr       */
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
	// else if (ft_strcmp("exit", cmd) == 0)
	// 	return (1);
	return (0);
}

// static int	exit_function(t_data *data, char **cmd)
// {
// 	make_exit(data, cmd);
// 	free_and_close_data(data, 59);
// 	free_env(&data->env);
// 	free(data->pids);
// 	free_tab(cmd);
// 	exit (data->result);
// 	return (0);
// }

int	exec_builtin(t_data *data, char **cmd, t_token *token)
{
	int	result;

	result = 0;
	(void) token;
	if (ft_strcmp("echo", cmd[0]) == 0)
		result = make_echo(data, cmd);
	else if (ft_strcmp("cd", cmd[0]) == 0)
		result = make_cd(data, cmd, data->env);
	else if (ft_strcmp("pwd", cmd[0]) == 0)
		result = make_pwd(data, data->env);
	else if (ft_strcmp("export", cmd[0]) == 0)
	{
		if (!data->env)
			return (FAILURE);
		result = make_export(data, cmd);
	}
	else if (ft_strcmp("unset", cmd[0]) == 0)
	{
		if (!data->env)
			return (FAILURE);
		result = make_unset(data, cmd);
	}
	else if (ft_strcmp("env", cmd[0]) == 0)
		result = make_env(data, data->env);
	// else if (ft_strcmp("exit", cmd[0]) == 0)
	// 	result = exit_function(data, cmd);
	return (result);
}
