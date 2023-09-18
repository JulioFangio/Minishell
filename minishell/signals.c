/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/09/15 17:59:32 by juduval          ###   ########.fr       */
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

void	redir(void)
{
	struct sigaction	si;
	struct sigaction	sq;

	si.sa_handler = sigint_handler;
	sigemptyset(&si.sa_mask);
	si.sa_flags = 0;
	sigaction(SIGINT, &si, NULL);
	sq.sa_handler = sigquit_handler;
	sigemptyset(&sq.sa_mask);
	sq.sa_flags = 0;
	sigaction(SIGQUIT, &sq, NULL);
}

int	start(char *line)
{
	char				**tab;
	t_cmd				*res;

	redir();
	tab = get_split(line);
	if (tab == (char **)1)
		return (1);
	res = get_cmd(tab);
	free_tab(tab);
	free_lst(res);
	return (1);
}

void	run_shell_loop(void)
{
	char	*line;

	using_history();
	while (42)
	{
		line = ft_readline();
		if (line == NULL)
			break ;
		if (!start(line))
			break ;
	}
	rl_clear_history();
}


//ca leak psk au moment ou je fais ctrl + d ca free pas la lst et/ou le tab
//sauf que le ctrl + d est gere avec le readline et je n ai pas acces a ces elements 
//du coup je ne peux pas reutiliser le readline ailleur pour gerer le ctrl + d