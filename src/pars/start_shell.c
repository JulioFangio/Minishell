/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:01:59 by juduval           #+#    #+#             */
/*   Updated: 2023/10/22 15:33:15 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start(char *line, t_data *data)
{
	data->tab = get_split(line);
	if (data->tab == NULL)
	{
		free_and_close_data(data, 96);
		return (1);
	}
	get_token(data);
	free_tab(data->tab);
	if (!parse_line(data))
	{
		data->result = 2;
		free_and_close_data(data, 0);
		return (1);
	}
	recuperate_data(data);
	check_heredoc(data);
	launch_minishell(data);
	//free_and_close_data(data, 45);
	return (1);
}

void	run_shell_loop(t_data *data)
{
	char	*line;

	using_history();
	redir(data);
	while (data->exit == 0)
	{
		line = ft_readline();
		if (line == NULL)
		{
			free_and_close_data(data, 101);
			free_env(&data->env);
			break ;
		}
		if (!start(line, data))
		{
			free_env(&data->env);
			break ;
		}
		//free_and_close_data(data, 99);
	}
	rl_clear_history();
}
