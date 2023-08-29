/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/08/29 19:27:15 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\033[2K", 4);
	rl_on_new_line();
	rl_redisplay();
	get_prompt();
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	get_prompt();
}

void	sigquit_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\033[2K", 4);
	rl_on_new_line();
	rl_redisplay();
	get_prompt();
}

void	sigterm_handler(int signum)
{
	(void)signum;
	//potentiel free a placer
	exit(0);
}

void	redir(void)
{
	struct sigaction	si;
	struct sigaction	sq;
	struct sigaction	st;

	si.sa_handler = sigint_handler;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);

	sq.sa_handler = sigquit_handler;
	sigemptyset(&sq.sa_mask);
	sq.sa_flags = 0;
	sigaction(SIGQUIT, &sq, NULL);

	st.sa_handler = sigterm_handler;
	sigemptyset(&st.sa_mask);
	st.sa_flags = 0;
	sigaction(SIGTERM, &st, NULL);
}

void	run_shell_loop(void)
{
	t_cmd	*cmd;
	using_history();

	while (1)
	{
		redir();
		cmd = get_cmd(get_split());
		while (cmd->next)
		{
			//---------------------------lstclear
			
		}
	}
	rl_clear_history();
}
