/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:40:34 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/13 20:16:30 by juduval          ###   ########.fr       */
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
	if (ft_strcmp("echo", cmd[0]) == 0)
		result = make_echo(data, cmd);
	if (ft_strcmp("cd", cmd[0]) == 0)
		result = make_cd(cmd, data->env);
	if (ft_strcmp("pwd", cmd[0]) == 0)
		result = make_pwd(data->env);
	if (ft_strcmp("export", cmd[0]) == 0 && token_is_pipe(token) == 0)
	{
	//	make_export(cmd, data, data->env, data->export);
		result = data->result;
	}
	if (ft_strcmp("unset", cmd[0]) == 0 && token_is_pipe(token) == 0)
		result = make_unset(cmd, data);
	if (ft_strcmp("env", cmd[0]) == 0)
		result = make_env(data->env);
	return (result);
}
