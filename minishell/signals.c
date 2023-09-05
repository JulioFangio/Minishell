/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/09/05 19:28:48 by juduval          ###   ########.fr       */
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
	char				*input;
	struct sigaction	si;
	struct sigaction	sq;

	if (get_cmd(get_split()) == 0)
		return (1);
	si.sa_handler = sigint_handler;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);
	sq.sa_handler = sigquit_handler;
	sigemptyset(&sq.sa_mask);
	sq.sa_flags = 0;
	sigaction(SIGQUIT, &sq, NULL);
	input = readline("/mnt/nfs/homes/juduval/Tronc commun/minishell$ ");
	if (input == NULL)
	{
		printf("exit\n");
		free(input);
		return (0);
	}
	free(input);
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
