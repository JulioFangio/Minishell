/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:36:37 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 20:16:35 by juduval          ###   ########.fr       */
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
	exit (data->result);
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
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (cmd && ft_strcmp(cmd[0], "exit") == 0)
		exit_function(data, cmd);
	if (cmd && ft_strcmp(cmd[0], "exit") != 0 && data->err_redir == 0)
		data->result = exec_bin(cmd, data, data->env);
	if (data->err_redir == 1)
	{
		free_tab(cmd);
		free_token(data->free_token);
		free_env(&data->env);
		free(data->pids);
	}
	free(data->pids);
	exit(data->result);
}

static void	end_exec_command(t_data *data, pid_t pid)
{
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
		&& data->err_redir == 0 && data->check == 0)
		exit_function(data, cmd);
	if (cmd && is_builtin(cmd[0]) && ft_strcmp(cmd[0], "exit") != 0
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
