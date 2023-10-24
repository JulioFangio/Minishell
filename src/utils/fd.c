/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:21:55 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 18:19:38 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_fd(int fd)
{
	if (fd > -1)
		close(fd);
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
		else if (tmp->next && tmp->next->str && (tmp->type == CHEVRON
				|| tmp->type == DOUBLE_CHEVRON))
		{
			ft_close_fd(data->fd_out);
			if (tmp->type == CHEVRON)
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
			else
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
		}
		tmp = tmp->next;
	}
}

void	ft_close_all_fd(t_data *data)
{
	if (data->fd_in > 2)
		ft_close_fd(data->fd_in);
	if (data->fd_out > 2)
		ft_close_fd(data->fd_out);
	if (data->pipefd[0] > 0)
		ft_close_fd(data->pipefd[0]);
	if (data->pipefd[1] > 0)
		ft_close_fd(data->pipefd[1]);
}

void	reset_to_initial_fd(t_data *data)
{
	data->fd_in = -1;
	data->fd_out = -1;
}
