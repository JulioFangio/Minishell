/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/13 23:00:11 by juduval          ###   ########.fr       */
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
			data->fd_out = open(tmp->next->str, O_CREAT | O_RDWR | O_TRUNC, 0666);
		}
		tmp = tmp->next;
	}
	printf("data in = %d et data out = %d\n", data->fd_in, data->fd_out);
}

void	exec_redir(t_data *data, t_token *token)
{
	put_fd_in_data(data);
	exec_command(data, token);
}

void	launch_minishell(t_data *data)
{
	int		status;
	t_token	*token;

	token = iter_token_cmd(data->token, 0);
	if (is_def_type(token, CHEVRON) || is_def_type(token, OPEN_CHEVRON)
		|| is_def_type(token, DOUBLE_CHEVRON))
		token = data->token->next;
		// token->next ou data->token->next?
	while (data->exit == 0 && token)
	{
		data->parent = 1;
		data->exec = 1;
		data->end = 1;
		exec_redir(data, token);
		ft_close_all_fd(data);
		reset_to_initial_fd(data);
		dup2(data->in, STDIN);
		dup2(data->out, data->fd_out);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (data->end == 0)
			data->result = status;
		if (data->parent == 0)
		{
			free_and_close_data(data, 8);
			exit(data->result);
		}
		data->err_redir = 0;
		token = iter_token_cmd(token, 1);
	}
}
