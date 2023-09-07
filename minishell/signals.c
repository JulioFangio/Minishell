/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/09/07 18:32:02 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
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

int	redir(void)
{
	struct sigaction	si;
	struct sigaction	sq;
	char				**tab;

	si.sa_handler = sigint_handler;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);
	sq.sa_handler = sigquit_handler;
	sigemptyset(&sq.sa_mask);
	sq.sa_flags = 0;
	sigaction(SIGQUIT, &sq, NULL);
	tab = get_split();
	if (tab == NULL)
		return (0);
	if (tab == (char **)1)
		return (1);
	get_cmd(tab);
	return (1);
}

void	run_shell_loop(void)
{
	using_history();
	while (42)
	{
		if (redir() == 0)
			break ;
	}
	rl_clear_history();
}
