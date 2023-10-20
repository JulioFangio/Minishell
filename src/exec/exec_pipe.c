/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:41:51 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/16 20:46:15 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_pipe(t_data *data)
{
	// int		pipefd[2];
	// int		i;

	// if (pipe(pipefd) < 0)
	// 	return (perror("pipe"));
	
	if (is_there_a_pipe(data->token))
		pipe(data->pipefd);
	else
	{
		data->pipefd[0] = -1;
		data->pipefd[1] = -1;
	}
	
		
	// data->pid = fork();
	// i = -1;
	// if (data->pid == 0)
	// {
	// 	if (data->fd_in != 0)
	// 		dup2(data->fd_in, STDIN_FILENO);
	// 	if (data->fd_out != 1)
	// 		dup2(data->fd_out, STDOUT_FILENO);
	// 	else
	// 		dup2(pipefd[1], STDOUT_FILENO);
	// 	close(pipefd[0]);
	// 	close(pipefd[1]);
	// 	data->pipe_in = pipefd[0];
	// 	data->parent = 0;
	// 	ft_putstr_fd("WHY ARE YOU GOING THERE?\n", 2);
	// 	printf("DATA TOKEN : %s\n", data->token->str);
	// 	exec_command(data, data->token);
	// 	exit (1);
	// }
	// else
	// {
	// 	ft_putstr_fd("WHEN ARE YOU HERE?\n", 2);
	// 	data->pids[data->idx_pid] = data->pid;
	// 		data->idx_pid++;
	// 	if (data->fd_in != 0)
	// 		dup2(data->fd_in, STDIN_FILENO);
	// 	else
	// 		dup2(pipefd[0], STDIN_FILENO);
	// 	if (data->fd_out != 1)
	// 		dup2(data->fd_out, STDOUT_FILENO);
	// 	close(pipefd[0]);
	// 	close(pipefd[1]);
	// 	data->pipe_out = pipefd[1];
	// 	data->end = 0;
	// 	if (!is_there_a_pipe(data->token))
	// 	{
	// 		while (++i < data->idx_pid -1)
	// 			waitpid(data->pids[i], NULL, 0);
	// 	}
	// }
}
