/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:41:51 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 12:20:13 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		data->pipefd[1] = -1;
	}
}
