/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:41:51 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/13 20:50:12 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_pipe(t_data *data)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		return (perror("pipe"), FAILURE);
	pid = fork();
	if (pid == 0)
	{
		ft_close_fd(pipefd[1]);
		if (data->fd_in != 0)
			dup2(data->fd_in, STDIN_FILENO);
		if (data->fd_out != 1)
			dup2(data->fd_out, STDOUT_FILENO);
		else
			dup2(pipefd[1], STDOUT_FILENO);
		data->pipe_in = pipefd[0];
		data->pid = -1;
		data->parent = 0;
		data->err_redir = 0;
		return (CHILD);
	}
	else
	{
		ft_close_fd(pipefd[0]);
		dup2(pipefd[1], data->fd_out);
		data->pipe_out = pipefd[1];
		data->pid = pid;
		data->end = 0;
		return (PARENT);
	}
}
