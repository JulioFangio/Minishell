/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:36:37 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/17 16:59:15 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	put_fd_in_data(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (is_there_a_pipe(data->token))
		data->fd_out = data->pipefd[1];
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->next && tmp->next->str && (tmp->type == OPEN_CHEVRON))
		{
			ft_close_fd(data->fd_in);
			data->fd_in = open(tmp->next->str, O_CREAT | O_RDWR, 0777);
		}
		else if (tmp->next && tmp->next->str && (tmp->type == CHEVRON
				|| tmp->type == DOUBLE_CHEVRON))
		{
			// if (data->fd_out != 1)
			// si double chevron changer open
			ft_close_fd(data->fd_out);
			if (tmp->type == CHEVRON)
				data->fd_out = open(tmp->next->str, O_CREAT | O_RDWR | O_TRUNC, 0777);
			else
				data->fd_out = open(tmp->next->str, O_CREAT | O_RDWR | O_APPEND, 0777);
		}
		tmp = tmp->next;
	}
}

static void check_exit_and_wait(t_data *data)
{
	int i = -1;
	if (!is_there_a_pipe(data->token))
	{
		data->end = 0;
		while (++i < data->idx_pid -1)
			waitpid(data->pids[i], NULL, 0);
	}
}


void	exec_command(t_data *data)
{
	char	**cmd;

	if (data->exec == 0)
		return ;
	put_fd_in_data(data);
	cmd = token_cmd_to_tab(data->token);
	if (!cmd)
		return;
	if (cmd && ft_strcmp(cmd[0], "exit") == 0
		&& token_is_pipe(data->token) == 0)
	{
		
		make_exit(data, cmd);
		return;
	}
	else if (cmd && is_builtin(cmd[0]) && ft_strcmp(cmd[0], "exit") != 0)
	{
		data->exec = exec_builtin(data, cmd, data->token);
		return;	
	}
	pid_t pid =fork();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pid == 0)
	{
		//close
		redir();
		if (cmd && ft_strcmp(cmd[0], "exit") != 0)
			exec_bin(cmd, data, data->env);
		
		//free des truc valgrind
		free_tab(cmd);
		// ft_close_fd(data->pipe_in);
		// ft_close_fd(data->pipe_out);
		//free token
		exit(data->result); //changer
	}
	data->pids[data->idx_pid] = pid;
	data->idx_pid++;
	if (is_there_a_pipe(data->token))
	{
		ft_close_fd(data->pipefd[1]);
		data->fd_in = data->pipefd[0];
	}
	check_exit_and_wait(data);
	return ;
}


