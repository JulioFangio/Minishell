/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:27:01 by juduval          ###   ########.fr       */
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
	t_data	*data;

	(void)signum;
	data = NULL;
	data = recuperate_data(data);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("^\\Quit (core dumped)", 1);
	printf("Ta soeur\n");
	free_and_close_data(data, 7);
	free_env(&data->env);
	exit (1);
}

void	redir(t_data *data)
{
	struct sigaction	si;
	struct sigaction	sq;

	si.sa_handler = sigint_handler;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);
	if (data->check_child == 0)
		signal(SIGQUIT, SIG_IGN);
	else
	{
		sq.sa_handler = sigquit_handler;
		sigemptyset(&sq.sa_mask);
		sq.sa_flags = 0;
		sigaction(SIGQUIT, &sq, NULL);
	}
}