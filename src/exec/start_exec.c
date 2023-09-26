/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/26 18:36:09 by jaristil         ###   ########.fr       */
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

void	do_redir(t_data *data, t_token *token, int type)
{
	ft_close_fd(data->fd_out);
	if (type == CHEVRON)
		data ->fd_out = open(token->str, O_CREAT, O_WRONLY);
		// verifier les flags pour open
	else
		data->fd_in = open(token->str, O_CREAT, O_WRONLY);
	if (data->fd_out < 0)
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(ERR_OPEN, STDERR);
		data->result = 1;
		data->err_redir = 1;
		return ;
	}
	dup2(data->fd_out, STDOUT);
}


void	redir_exec(t_data *data, t_token *token)
{
	int		pipe;
	t_token	*next_tok;
	t_token	*prev_tok;

	pipe = 0;
	next_tok = get_next_token(token, 0);
	prev_tok = get_prev_token(token, 0);
	if (is_type(prev_tok, CHEVRON))
		do_redir(data, token, CHEVRON);
	else if (is_type(prev_tok, DOUBLE_CHEVRON))
		do_redir(data, token, DOUBLE_CHEVRON);
	else if (is_type(prev_tok, PIPE))
		pipe = do_pipe(data);
	//else if (is_type(prev_tok, OPEN_CHEVRON))
	//	is_open_chev(data, token);
	//else if (is_type(prev_tok, HERE_DOC))
	//	is_here_doc(data, token);
	if (next_tok && is_type(next_tok, END) == 0 && pipe != 1)
		redir_exec(data, next_tok->next);
	if ((is_type(prev_tok, END) || is_type(prev_tok, PIPE) || !prev_tok)
		&& data->err_redir == 0 && pipe != 1)
		exec_command(data, token);
}

void	launch_minishell(t_data *data)
{
	int		status;

	while (data->exit == 0 && data->token)
	{
		data->parent = 1;
		data->exec = 1;
		data->end = 1;
		redir_exec(data, data->token);
		ft_close_all_fd(data);
		reset_to_initial_fd(data);
		dup2(data->in, STDIN);
		dup2(data->out, STDOUT);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (data->end == 0)
			data->result = status;
		if (data->parent == 0)
		{
			free_and_close(data);
			exit(data->result);
		}
		data->err_redir = 0;
	}
}
