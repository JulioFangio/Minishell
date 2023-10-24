/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 18:19:12 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_redir(t_data *data)
{
	do_pipe(data);
	exec_command(data);
}

void    launch_minishell(t_data *data)
{
    int			status;
    t_token		*token;
	t_token		*forfree;

    status = 0;
	forfree = data->token;
    set_pid_tab(data);
    data->check = is_there_a_pipe(data->token);
    data->idx_pid = 0;
    token = iter_token_cmd(data->token, 0);
    while (data->exit == 0 && token)
    {
        data->exec = 1;
		data->err_redir = 0;
		if (!is_there_a_pipe(data->token) && is_builtin(data->token->str))
	    	reset_to_initial_fd(data);
        exec_redir(data);
        token = iter_token_cmd(token, 1);
        data->token = token;
    }
	ft_close_all_fd(data); 
    int i = -1;
    while (++i < data->idx_pid)
	{
        waitpid(data->pids[i], &status, 0);
	}
	status = WEXITSTATUS(status);
	if (data->end == 0)
    	data->result = status;
    data->idx_pid = 0;
	free_token(forfree);
    free(data->pids);
}
		