/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:01:59 by juduval           #+#    #+#             */
/*   Updated: 2023/10/08 13:29:13 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start(char *line, t_data *data)
{
	char				**tab;
	t_token				*token;

	tab = get_split(line);
	if (tab == (char **)1)
		return (1);
	token = get_token(tab);
	data->token = token;
	if (!parse_line(token, tab))
	{
		free_and_close_data(data);
		free_tab(tab);
		return (1);
	}
	launch_minishell(data);
	free_and_close_data(data);
	free_tab(tab);
	return (1);
}

void	run_shell_loop(t_data *data)
{
	char	*line;

	using_history();
	redir();
	while (42)
	{
		line = ft_readline();
		if (line == NULL)
			break ;
		if (!start(line, data))
			break ;
	}
	rl_clear_history();
}