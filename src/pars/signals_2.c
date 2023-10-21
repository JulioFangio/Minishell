/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:46:22 by juduval           #+#    #+#             */
/*   Updated: 2023/10/21 20:40:15 by juduval          ###   ########.fr       */
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
	data->result = 130;
	free_and_close_data(data, 7);
	free_env(&data->env);
	// rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
	exit (1);
}

void	sigquit_handler_hd(int signum)
{
	(void)signum;
	signal(SIGQUIT, SIG_IGN);
	write(STDOUT_FILENO, "\033[2K", 4);
	rl_replace_line("", 1);
}

	// t_data	*data;

	// (void)signum;
	// data = NULL;
	// data = recuperate_data(data);
	// // write(STDOUT_FILENO, "\033[2K", 4);
	// ft_putendl_fd("^\\Quit (core dumped)", 2);
	// free_and_close_data(data, 7);
	// free_env(&data->env);
	// exit (1);

void	redir_hd(t_data *data)
{
	struct sigaction	si;
	// struct sigaction	sq;

	(void)data;
	si.sa_handler = sigint_handler_hd;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);
	// sq.sa_handler = sigquit_handler_hd;
	// sigemptyset(&sq.sa_mask);
	// sq.sa_flags = 0;
	// sigaction(SIGQUIT, &sq, NULL);
	signal(SIGQUIT, SIG_IGN);
}
