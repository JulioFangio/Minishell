/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:01:59 by juduval           #+#    #+#             */
/*   Updated: 2023/10/25 20:30:10 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start(char *line, t_data *data)
{
	data->tab = get_split(line);
	if (data->tab == NULL)
		return (1);
	get_token(data);
	data->free_token = data->token;
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
			free_env(&data->env);
			break ;
		}
		if (!start(line, data))
		{
			free_env(&data->env);
			break ;
		}
	}
	rl_clear_history();
}
