/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:36:37 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 17:03:59 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exit_function(t_data *data, char **cmd)
{
	make_exit(data, cmd);
	free_and_close_data(data, 59);
	free_env(&data->env);
	free(data->pids);
	free_tab(cmd);
	exit (1);
}

static void	builtin_function(t_data *data, char **cmd)
{
	if (is_there_a_pipe(data->token))
	{
		data->result = exec_builtin(data, cmd, data->token);
		ft_close_fd(data->fd_out);
		ft_close_fd(data->fd_in);
		data->fd_in = -1;
		data->fd_in = data->pipefd[0];
	}
	else
		data->result = exec_builtin(data, cmd, data->token);
}

static void	bin_function(t_data *data, char **cmd)
{
	data->check_child = 1;
	redir(data);
	if (cmd && ft_strcmp(cmd[0], "exit") != 0 && data->err_redir == 0)
		data->result = exec_bin(cmd, data, data->env);
	free(data->pids);
	// exit(data->result);	
}

static void	end_exec_command(t_data *data, pid_t pid)
{
	data->check_child = 0;
	redir(data);
	data->pids[data->idx_pid] = pid;
	data->idx_pid++;
	if (data->fd_in > 0)
	{
		close(data->fd_in);
		data->fd_in = -1;
	}
	if (is_there_a_pipe(data->token))
	{
		ft_close_fd(data->pipefd[1]);
		data->fd_in = data->pipefd[0];
	}
	check_exit_and_wait(data);
}

void	exec_command(t_data *data)
{
	char	**cmd;
	pid_t	pid;

	if (data->exec == 0)
		return ;
	put_fd_in_data(data);
	cmd = token_cmd_to_tab(data->token);
	if (!cmd)
		return ;
	if (cmd && ft_strcmp(cmd[0], "exit") == 0
		&& token_is_pipe(data->token) == 0 && data->err_redir == 0)
		exit_function(data, cmd);
	else if (cmd && is_builtin(cmd[0]) && ft_strcmp(cmd[0], "exit") != 0
		&& data->err_redir == 0)
	{
		builtin_function(data, cmd);
		return (free_tab(cmd));
	}
	pid = fork();
	if (pid == 0)
		bin_function(data, cmd);
	end_exec_command(data, pid);
	data->exec = 0;
	return (free_tab(cmd));
}
