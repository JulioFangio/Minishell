/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/12 21:20:34 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_redir(t_data *data, t_token *token)
{
	int		pipe;
	t_token	*next_tok;
	t_token	*prev_tok;

	pipe = 0;
	next_tok = get_next_token(token, 0);
	prev_tok = get_prev_token(token, 0);
	// if (check_token(prev_tok, CHEVRON))
	// {
	// 	printf("I AM INSIDE CHEVRON\n");
	// 	do_redir(data, token, CHEVRON);
	// }
	// else if (check_token(prev_tok, DOUBLE_CHEVRON))
	// {
	// 	printf("I AM INSIDE DOUBLE CHEVRON\n");
	// 	do_redir(data, token, DOUBLE_CHEVRON);
	// }
	// else if (check_token(prev_tok, OPEN_CHEVRON))
	// {
	// 	redir_chev(data, token);
	// }
	if (check_token(prev_tok, PIPE))
	{
		pipe = do_pipe(data);
	}
	if ((check_token(prev_tok, PIPE) || !prev_tok)
		&& data->err_redir == 0 && pipe != 1)
	{
		exec_command(data, token);
	}
}

void	put_fd_in_data(t_data *data)
{
	t_token	*tmp;
	int		checkin;
	int		checkout;

	checkin = 0;
	checkout = 0;
	tmp = data->token;
	while (tmp && tmp->type != 3)
	{
		if (tmp->type == OPEN_CHEVRON || tmp->type == HERE_DOC)
		{
			data->fd_in = tmp->fd;
			checkin = 1;
		}
		else if (tmp->type == CHEVRON || tmp->type == DOUBLE_CHEVRON)
		{
			data->fd_out = tmp->fd;
			checkout = 1;
		}
		tmp = tmp->next;
	}
	if (checkin == 0)
		data->fd_in = 0;
	if (checkout == 0)
		data->fd_out = 1;
}

void	launch_minishell(t_data *data)
{
	int		status;
	t_token	*token;

	token = iter_token_cmd(data->token, 0);
	// if (is_def_type(token, CHEVRON) || is_def_type(token, OPEN_CHEVRON)
	// 	|| is_def_type(token, DOUBLE_CHEVRON))
	// 	token = data->token->next;
	while (data->exit == 0 && token)
	{
		data->parent = 1;
		data->exec = 1;
		data->end = 1;
		put_fd_in_data(data);
		exec_redir(data, token);
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
			free_and_close_data(data, 8);
			free_env(data->env);
			exit(data->result);
		}
		data->err_redir = 0;
		token = iter_token_cmd(token, 1);
	}
}
