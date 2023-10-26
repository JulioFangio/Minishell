/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/26 14:21:34 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_redir(t_data *data)
{
	do_pipe(data);
	exec_command(data);
}

static void	wait_and_recuperate_code(t_data *data)
{
	int			status;
	int			i;

	status = 0;
	i = -1;
	while (++i < data->idx_pid)
	{
		waitpid(data->pids[i], &status, 0);
	}
	redir(data);
	if (WIFEXITED(status))
		data->result = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			ft_putchar_fd('\n', 1);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", 1);
		data->result = 128 + WTERMSIG(status);
	}
}

static void	do_the_exec(t_data *data)
{
	t_token		*token;

	token = iter_token_cmd(data->token, 0);
	data->check = is_there_a_pipe(data->token);
	data->idx_pid = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
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
	wait_and_recuperate_code(data);
}

void	launch_minishell(t_data *data)
{
	t_token		*forfree;

	forfree = data->token;
	set_pid_tab(data);
	do_the_exec(data);
	ft_close_all_fd(data);
	data->idx_pid = 0;
	free_token(forfree);
	free(data->pids);
}
