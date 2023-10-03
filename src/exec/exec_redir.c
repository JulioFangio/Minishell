/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:12:32 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/03 15:49:24 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_redir(t_data *data, t_token *token, int type)
{
	ft_close_fd(data->fd_out);
	if (type == CHEVRON)
		data ->fd_out = open(token->str, O_CREAT, O_WRONLY, O_TRUNC);
	else
		data->fd_out = open(token->str, O_CREAT, O_WRONLY, O_APPEND);
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

void	redir_chev(t_data *data, t_token *token)
{
	ft_close_fd(data->fd_in);
	// in pipex it make mistake but normally fixed and ensure that
	// the old open file is well closed
	data->fd_in = open(token->str, O_RDONLY);
	if (data->fd_in < 0)
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(ERR_OPEN, STDERR);
		data->result = FAILURE;
		data->err_redir = FAILURE;
		return ;
	}
	dup2(data->fd_in, STDIN);
}

void	open_heredoc(t_data *data)
{
	data->fd_in = open(".heredoc", O_RDONLY);
	if (data->fd_in < 0)
	{
		ft_putstr_fd(ERR_OPEN, STDERR);
		data->result = FAILURE;
		data->err_redir = FAILURE;
		return ;
	}
	unlink(".heredoc");
	dup2(data->fd_in, STDIN);
}

// create pipe from in to take all the input write in the << data->pipefd[0]
// and  give the out of pipe to write data->pipefd[1]
void	redir_heredoc(t_data *data, t_token *token)
{
	char	*hd_file = NULL; // en attendant d'avoir recup input de ju
	int		fd;

	unlink(".heredoc");
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// verifier flags
	if (fd < 0 || !(token->str) || ft_strlen(token->str) == 0)
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(ERR_OPEN, STDERR);
		data->err_redir = FAILURE;
		data->result = FAILURE;
		return ;
	}
	// hd_file = // ce que ju recup sous forme de *str(token->str);
	if (!hd_file)
		ft_putstr_fd("", fd);
		// it write an empty stirng inside the file .heredoc
		// so jules has to return NULL if he can't find occurence
	else
		ft_putstr_fd(hd_file, fd);
	free(hd_file);
	close(fd);
	open_heredoc(data);
}
