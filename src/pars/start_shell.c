/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:01:59 by juduval           #+#    #+#             */
/*   Updated: 2023/10/12 17:52:30 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start(char *line, t_data *data)
{
	t_token				*token;

	data->tab = get_split(line);
	if (data->tab == (char **)1)
		return (1);
	token = get_token(data->tab);
	data->token = token;
	if (!parse_line(data))
	{
		free_and_close_data(data, 0);
		return (1);
	}
	recuperate_fds(data);
	recuperate_data(data);
	check_heredoc(data);
	launch_minishell(data);
	free_and_close_data(data, 45);
	return (1);
}

void	run_shell_loop(t_data *data)
{
	char	*line;

	using_history();
	redir();
	while (42 && data->exit == 0)
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
