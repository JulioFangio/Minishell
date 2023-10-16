/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:41:51 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/15 19:20:09 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_pipe(t_data *data)
{
	// pid_t	pid;
	int		pipefd[2];
	int		i;

	if (pipe(pipefd) < 0)
		return (perror("pipe"));
	// appeler la fonction retour code erreur exit si fail
	data->pid = fork();
	i = -1;
	if (data->pid == 0)
	{
		if (data->fd_in != 0)
			dup2(data->fd_in, STDIN_FILENO);
		if (data->fd_out != 1)
			dup2(data->fd_out, STDOUT_FILENO);
		else
			dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		// data->pipe_in = pipefd[0];
		// data->pid = -1;
		data->parent = 0;
		data->err_redir = 0;
		exec_command(data, data->token);
		exit (1);
	}
	else
	{
		data->pids[data->idx_pid] = data->pid;
			data->idx_pid++;
		if (data->fd_in != 0)
			dup2(data->fd_in, STDIN_FILENO);
		else
			dup2(pipefd[0], STDIN_FILENO);
		if (data->fd_out != 1)
			dup2(data->fd_out, STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		data->pipe_out = pipefd[1];
		// data->pid = pid;
		data->end = 0;
		if (!is_there_a_pipe(data->token))
		{
			while (++i < data->idx_pid -1)
				waitpid(data->pids[i], NULL, 0);
		}
	}
}
