/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:21:55 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/25 15:41:41 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_fd(int fd)
{
	if (fd > 2)
		close(fd);
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
