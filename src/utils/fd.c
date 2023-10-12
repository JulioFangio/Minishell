/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:21:55 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/12 21:10:39 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_close_all_fd(t_data *data)
{
	ft_close_fd(data->fd_in);
	ft_close_fd(data->fd_out);
	ft_close_fd(data->pipe_in);
	ft_close_fd(data->pipe_out);
}

void	reset_to_initial_fd(t_data *data)
{
	data->pid = -1;
	data->fd_in = 0;
	data->fd_out = 1;
	data->pipe_in = -1;
	data->pipe_out = -1;
}
