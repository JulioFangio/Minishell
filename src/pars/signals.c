/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/10/21 18:42:15 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_handler(int signum)
{
	(void)signum;
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(get_prompt(), 1);
	// rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
}

void	sigquit_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\033[2K", 4);
	rl_on_new_line();
	rl_redisplay();
	get_prompt();
}

void	redir(void)
{
	struct sigaction	si;
	// struct sigaction	sq;

	// printf("je passe la\n");
	si.sa_handler = sigint_handler;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);
	// sq.sa_handler = sigquit_handler;
	// sigemptyset(&sq.sa_mask);
	// sq.sa_flags = 0;
	// sigaction(SIGQUIT, &sq, NULL);
	signal(SIGQUIT, SIG_IGN);
}

// void    sigint_handler_cmd(int signum)
// {
// 	t_data    *data;

// 	(void)signum;
// 	data = NULL;
// 	data = recuperate_data(data);
// 	free_and_close_data(data, 7);
// 	free_env(&data->env);
// 	exit (1);
// }

// void    sigquit_handler_cmd(int signum)
// {
// 	t_data	*data;

// 	(void)signum;
// 	data = NULL;
// 	data = recuperate_data(data);
// 	ft_putendl_fd("^\\Quit (core dumped)", 2);
// 	free_and_close_data(data, 7);
// 	free_env(&data->env);
// 	exit (1);
// }

// void    redir_cmd(t_data *data)
// {
// 	struct sigaction    si;
// 	struct sigaction    sq;

// 	(void)data;
// 	si.sa_handler = sigint_handler_cmd;
// 	sigemptyset(&si.sa_mask);
// 	si.sa_flags = 0;
// 	sigaction(SIGINT, &si, NULL);
// 	sq.sa_handler = sigquit_handler_cmd;
// 	sigemptyset(&sq.sa_mask);
// 	sq.sa_flags = 0;
// 	sigaction(SIGQUIT, &sq, NULL);
// }

// void    sigint_handler_child(int signum)
// {
// 	(void)signum;
// 	ft_putchar_fd('\n', 1);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }

// void    sigquit_handler_child(int signum)
// {
// 	(void)signum;
// 	write(STDOUT_FILENO, "\033[2K", 4);
// 	rl_on_new_line();
// 	rl_redisplay();
// 	get_prompt();
// }

// void    redir_child(t_data *data)
// {
// 	struct sigaction    si;
// 	struct sigaction    sq;

// 	(void)data;
// 	si.sa_handler = sigint_handler_child;
// 	sigemptyset(&si.sa_mask);
// 	si.sa_flags = 0;
// 	sigaction(SIGINT, &si, NULL);
// 	sq.sa_handler = sigquit_handler_child;
// 	sigemptyset(&sq.sa_mask);
// 	sq.sa_flags = 0;
// 	sigaction(SIGQUIT, &sq, NULL);
// }