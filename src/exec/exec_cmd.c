/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:36:37 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/15 18:36:25 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	put_fd_in_data(t_data *data)
{
	t_token	*tmp;

	if (data->check_hdc != 1)
		data->fd_in = 0;
	data->fd_out = 1;
	tmp = data->token;
	while (tmp && tmp->type != 3)
	{
		if (tmp->next && tmp->next->str && (tmp->type == OPEN_CHEVRON))
			data->fd_in = open(tmp->next->str, O_CREAT, O_RDWR, 0666);
		else if (tmp->next && tmp->next->str && (tmp->type == CHEVRON
				|| tmp->type == DOUBLE_CHEVRON))
		{
			if (data->fd_out != 1)
				close(data->fd_out);
			data->fd_out = open(tmp->next->str,
					O_CREAT | O_RDWR | O_TRUNC, 0666);
		}
		tmp = tmp->next;
	}
}

void	exec_command(t_data *data, t_token *token)
{
	char	**cmd;

	if (data->exec == 0)
		return ;
	put_fd_in_data(data);
	cmd = token_cmd_to_tab(token);
	if (cmd && ft_strcmp(cmd[0], "exit") == 0
		&& token_is_pipe(token) == 0)
		make_exit(data, cmd);
	else if (cmd && is_builtin(cmd[0]) && ft_strcmp(cmd[0], "exit") != 0)
		data->exec = exec_builtin(data, cmd, token);
	else if (cmd && ft_strcmp(cmd[0], "exit") != 0)
		data->result = exec_bin(cmd, data, data->env);
	free_tab(cmd);
	ft_close_fd(data->pipe_in);
	ft_close_fd(data->pipe_out);
	data->pipe_in = -1;
	data->pipe_out = -1;
	data->exec = 0;
	data->fd_in = 0;
	data->fd_out = 1;
	return ;
}
