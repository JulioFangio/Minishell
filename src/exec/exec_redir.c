/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:11:25 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/25 20:42:47 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	redir_openchevron(t_data *data, t_token *tmp)
{
	ft_close_fd(data->fd_in);
	data->fd_in = open(tmp->next->str, O_CREAT | O_RDWR, 0777);
	if (data->fd_in < 0)
	{
		ft_putstr_fd(ERR_OPEN, 2);
		data->result = 1;
		data->err_redir = 1;
	}
}

static void	redir_chevron(t_data *data, t_token *tmp)
{
	data->fd_out = open(tmp->next->str, O_CREAT | O_RDWR
			| O_TRUNC, 0777);
	if (data->fd_out < 0)
	{
		ft_putstr_fd(ERR_OPEN, 2);
		data->result = 1;
		data->err_redir = 1;
	}
}

static void	redir_doublechevron(t_data *data, t_token *tmp)
{
	data->fd_out = open(tmp->next->str, O_CREAT | O_RDWR
			| O_APPEND, 0777);
	if (data->fd_out < 0)
	{
		ft_putstr_fd(ERR_OPEN, 2);
		data->result = 1;
		data->err_redir = 1;
	}
}

void	put_fd_in_data(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	if (is_there_a_pipe(data->token))
		data->fd_out = data->pipefd[1];
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->next && tmp->next->str && (tmp->type == OPEN_CHEVRON))
			redir_openchevron(data, tmp);
		else if (tmp->next && tmp->next->str && (tmp->type == CHEVRON
				|| tmp->type == DOUBLE_CHEVRON))
		{
			ft_close_fd(data->fd_out);
			if (tmp->type == CHEVRON)
				redir_chevron(data, tmp);
			else
				redir_doublechevron(data, tmp);
		}
		tmp = tmp->next;
	}
}
