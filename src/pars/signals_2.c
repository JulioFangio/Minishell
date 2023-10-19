/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:46:22 by juduval           #+#    #+#             */
/*   Updated: 2023/10/19 18:21:36 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*recuperate_data(t_data *data)
{
	static t_data	*duplicate;

	if (data)
		duplicate = data;
	return (duplicate);
}

void	sigint_handler_hd(int signum)
{
	t_data	*data;

	(void)signum;
	data = NULL;
	data = recuperate_data(data);
	free_and_close_data(data, 7);
	free_env(&data->env);
	exit (1);
}

void	sigquit_handler_hd(int signum)
{
	t_data	*data;

	(void)signum;
	data = NULL;
	data = recuperate_data(data);
	// write(STDOUT_FILENO, "\033[2K", 4);
	ft_putendl_fd("^\\Quit (core dumped)", 2);
	free_and_close_data(data, 7);
	free_env(&data->env);
	exit (1);
	// rl_redisplay();
	// get_prompt_heredoc();
}

void	redir_hd(t_data *data)
{
	struct sigaction	si;
	struct sigaction	sq;

	(void)data;
	si.sa_handler = sigint_handler_hd;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);
	sq.sa_handler = sigquit_handler_hd;
	sigemptyset(&sq.sa_mask);
	sq.sa_flags = 0;
	sigaction(SIGQUIT, &sq, NULL);
}

//lol