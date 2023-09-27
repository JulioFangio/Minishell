/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:41:51 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/27 15:44:11 by jaristil         ###   ########.fr       */
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
		dup2(pipefd[0], STDIN);
		data->pipe_in = pipefd[0];
		data->pid = -1;
		data->parent = 0;
		data->err_redir = 0;
		return (CHILD);
	}
	else
	{
		ft_close_fd(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		data->pipe_out = pipefd[1];
		data->pid = pid;
		data->end = 0;
		return (PARENT);
	}
}
