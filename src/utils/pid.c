/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:30:16 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 17:51:45 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_pid_tab(t_data *data)
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

void	check_exit_and_wait(t_data *data)
{
	int	i;

	i = -1;
	if (!is_there_a_pipe(data->token))
	{
		while (++i < data->idx_pid -1)
			waitpid(data->pids[i], NULL, 0);
	}
}
