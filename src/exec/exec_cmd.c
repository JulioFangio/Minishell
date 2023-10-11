/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:36:37 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/11 14:45:33 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_command(t_data *data, t_token *token)
{
	char	**cmd;

	if (data->exec == 0)
		return ;
	cmd = token_cmd_to_tab(token);
	if (cmd && ft_strcmp(cmd[0], "exit") == 0
		&& token_is_pipe(token) == 0)
		make_exit(data, cmd);
	else if (cmd && is_builtin(cmd[0]) && ft_strcmp(cmd[0], "exit") != 0)
		data->exec = exec_builtin(data, cmd, token);
	else if (cmd && ft_strcmp(cmd[0], "exit") != 0)
		data->result = exec_bin(cmd, data, data->env);
	free_tab(cmd);
	ft_close_fd(data->pipe_in);
	ft_close_fd(data->pipe_out);
	data->pipe_in = -1;
	data->pipe_out = -1;
	data->exec = 0;
}
