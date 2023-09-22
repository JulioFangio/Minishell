/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/22 17:48:16 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redir_exec(t_data *data, t_token *token)
{
	int		pipe;
	t_token	*prev_tok;
	t_token	*next_tok;

	//next_tok = (); // jules
	//prev_tok = (); // jules
	/* pipe = 0;
	if (is_type(prev_tok, CHEVRON))
		redir(data, token, CHEVRON);
	else if (is_type(prev_tok, DOUBLE_CHEVRON))
		redir(data, token, DOUBLE_CHEVRON);
	else if (is_type(prev_tok, PIPE))
		pipe = is_pipe(data);
	else if (is_type(prev_tok, OPEN_CHEVRON))
		is_open_chev(data, token);
	else if (is_type(prev_tok, DOUBLE_INPUT))
		is_here_doc(data, token);
	if (next_tok && is_type(next_tok, END) == 0 && pipe != 1)
		redir_exec(data, next_tok->next);
	if ((is_type(prev_tok, END) || is_type(prev_tok, PIPE) || !prev_tok)
		&& pipe != 1) */
	exec_command(data, token);
}

void	launch_minishell(t_data *data)
{
	int		status;

	while (data->exit == 0 && data->token)
	{
		data->parent = 1;
		data->exec = 1;
		data->end = 1;
		redir_exec(data, data->token);
		waitpid(-1, &status, 0);
		WEXITSTATUS(status);
		if (data->end == 0)
			data->result = status;
	}
}
