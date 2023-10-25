/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:41:51 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/25 18:58:41 by jaristil         ###   ########.fr       */
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

void	do_pipe(t_data *data)
{
	if (is_there_a_pipe(data->token))
	{
		if (pipe(data->pipefd) < 0)
			perror("pipe");
	}
	else
	{
		data->pipefd[0] = -1;
		ft_close_fd(data->pipefd[1]);
		data->pipefd[1] = -1;
	}
}
