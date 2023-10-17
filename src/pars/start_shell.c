/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:01:59 by juduval           #+#    #+#             */
/*   Updated: 2023/10/17 16:38:36 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start(char *line, t_data *data)
{
	data->tab = get_split(data, line);
	get_token(data);
	if (!parse_line(data))
	{
		free_and_close_data(data, 0);
		return (1);
	}
	recuperate_data(data);
	check_heredoc(data);
	if (!parse_ls(data, 0))
	{
		free_and_close_data(data, 0);
		return (1);
	}
	launch_minishell(data);
	free_and_close_data(data, 45);
	return (1);
}

void	run_shell_loop(t_data *data)
{
	char	*line;

	using_history();
	redir();
	while (data->exit == 0)
	{
		line = ft_readline();
		if (line == NULL)
			break ;
		if (!start(line, data))
			break ;
	}
	free_env(data->env);
	rl_clear_history();
}
