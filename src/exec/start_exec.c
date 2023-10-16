/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:26:36 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/15 19:24:00 by juduval          ###   ########.fr       */
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

void	exec_redir(t_data *data, t_token *token, int nb)
{
	//redefinir les fd aux nouvelles valeurs des redirections pour la cmd avant le pipe 
	if (nb == 1)
		do_pipe(data);
	else
		exec_command(data, token);
	//executer la commande avec les bons fd
	//rediriger les fd de la comande et les setups pour la comande c + 1 apres le pipe
}

static void	set_pid_tab(t_data *data)
{
	int		count;
	t_token	*tmp;

	count = 0;
	tmp = data->token;
	while (tmp)
	{
		if (tmp->type == 3)
			count++;
		tmp = tmp->next;
	}
	data->pids = ft_calloc(count, sizeof(int));
	// prtect
}

void	launch_minishell(t_data *data)
{
	int		status;
	t_token	*token;
	int 	check;

	set_pid_tab(data);
	check = is_there_a_pipe(data->token);
	data->idx_pid = 0;
	token = iter_token_cmd(data->token, 0);
	while (data->exit == 0 && token)
	{
		data->parent = 1;
		data->exec = 1;
		data->end = 1;
		exec_redir(data, token, check);
		ft_close_all_fd(data);
		reset_to_initial_fd(data);
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
		data->token = token;
	}
	data->idx_pid = 0;
	free(data->pids);
}
