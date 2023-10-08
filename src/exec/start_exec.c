/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/08 15:54:00 by jaristil         ###   ########.fr       */
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
	if (check_token(prev_tok, CHEVRON) == SUCCESS)
		do_redir(data, token, CHEVRON);
	else if (check_token(prev_tok, DOUBLE_CHEVRON) == SUCCESS)
		do_redir(data, token, DOUBLE_CHEVRON);
	else if (check_token(prev_tok, PIPE) == SUCCESS)
		pipe = do_pipe(data);
	else if (check_token(prev_tok, OPEN_CHEVRON) == SUCCESS)
		redir_chev(data, token);
	else if (check_token(prev_tok, HERE_DOC) == SUCCESS)
		redir_heredoc(data, token);
	if (next_tok && check_token(next_tok, END) == FAILURE && pipe != 1)
		exec_redir(data, next_tok->next);
	if ((check_token(prev_tok, END) || check_token(prev_tok, PIPE)
			|| !prev_tok) && data->err_redir == 0 && pipe != 1)
		exec_command(data, token);
}

// check les appels systeme
void	launch_minishell(t_data *data)
{
	int		status;
	t_token	*token;

	//while (data->exit == 0 && data->token)
	//{
	token = iter_token_cmd(data->token, 0);
	data->parent = 1;
	data->exec = 1;
	data->end = 1;
	exec_redir(data, data->token);
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
		free_and_close_data(data);
		exit(data->result);
	}
	data->err_redir = 0;
	token = iter_token_cmd(data->token, 1);
	//}
}
