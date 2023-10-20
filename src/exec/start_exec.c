/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/19 17:28:29 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_there_a_pipe(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	exec_redir(t_data *data)
{
	
	do_pipe(data);
	exec_command(data);
}

static void	set_pid_tab(t_data *data)
{
	int		count;
	t_token	*tmp;

	count = 0;
	tmp = data->token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			count++;
		tmp = tmp->next;
	}
	data->pids = ft_calloc(count + 1, sizeof(int));
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
        data->parent = 1;
        data->exec = 1;
        data->end = 1;
        exec_redir(data);
        token = iter_token_cmd(token, 1);
        data->token = token;
    }
    ft_close_all_fd(data); 
    reset_to_initial_fd(data);
    int i = -1;
    while(++i < data->idx_pid)
    {
        waitpid(data->pids[i], &status, 0);
        redir();
    }
    data->result = WEXITSTATUS(status);
    data->idx_pid = 0;
	free_token(forfree);
    free(data->pids);
}
		