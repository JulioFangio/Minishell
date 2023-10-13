/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/12 16:49:36 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_redir(t_data *data, t_token *token)
{
	int		pipe;
	t_token	*prev_tok;

	pipe = 0;
	prev_tok = get_prev_token(token, 0);
	//printf("INSIDE CHEVRON: %s\n", prev_tok->str);
	if (check_token(prev_tok, CHEVRON))
	{
		if (prev_tok)
			printf("INSIDE CHEVRON: %s\n", prev_tok->str);
		do_redir(data, token, CHEVRON);
	}
	else if (check_token(prev_tok, DOUBLE_CHEVRON))
		do_redir(data, token, DOUBLE_CHEVRON);
	else if (check_token(prev_tok, OPEN_CHEVRON))
		redir_chev(data, token);
	else if (check_token(prev_tok, PIPE))
		pipe = do_pipe(data);
	if ((check_token(prev_tok, PIPE) || !prev_tok)
		&& data->err_redir == 0 && pipe != 1)
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
		dup2(data->out, STDOUT);
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
