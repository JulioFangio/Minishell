/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:12:32 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/09 11:55:08 by jaristil         ###   ########.fr       */
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
	if (data->fd_out == -1)
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(ERR_OPEN, STDERR);
		data->result = FAILURE;
		data->err_redir = FAILURE;
		return ;
	}
	dup2(data->fd_out, STDOUT);
}

void	redir_chev(t_data *data, t_token *token)
{
	ft_close_fd(data->fd_in);
	data->fd_in = open(token->str, O_RDONLY);
	if (data->fd_in == -1)
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(ERR_OPEN, STDERR);
		data->result = FAILURE;
		data->err_redir = FAILURE;
		return ;
	}
	dup2(data->fd_in, STDIN);
}
