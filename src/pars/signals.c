/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:01:21 by juduval           #+#    #+#             */
/*   Updated: 2023/10/03 17:35:09 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

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

int	start(char *line, t_data *data)
{
	char				**tab;
	t_token				*res;

	tab = get_split(line);
	if (tab == (char **)1)
		return (1);
	res = get_token(tab);
	data->token = res;
	if (!parse_line(res))
	{
		free_data(data);
		free_tab(tab);
		free_lst(res);
		return (1);
	}
	launch_minishell(data);
	/* free_tab(tab);
	free_lst(res);
	free_data(data); */
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

// 1 === convertir les t_token en t_token pour compatibilite avec la struct de juv
// 2 === creer une fonction qui lis la liste chainee avec pour limite les pipes 
// et qui cree un tableau de tableau comportant cmd/builtin + les options et les args
// 3 === reflechir au fait de creer une nouvelle structure en tableau pour y stocker
// le tableau en question et les redirections avec leurs fd


// rentrer dans data puis free while la liste de t_env puis free data 