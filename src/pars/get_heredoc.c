/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:13 by juduval           #+#    #+#             */
/*   Updated: 2023/10/21 20:53:27 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_prompt_heredoc(void)
{
	char	*prompt;

	prompt = ft_strdup("> ");
	return (prompt);
}

static void	get_out_of_heredoc(t_data *data, t_token *token, char *line)
{
	// if (line == NULL)
	// {
	// 	ft_putstr_fd("warning: here-document delimited", 2);
	// 	ft_putstr_fd(" by end-of-file (wanted `", 2);
	// 	ft_putstr_fd(token->next->str, 2);
	// 	ft_putendl_fd("')", 2);
	// }
	(void)token;
	free_and_close_data(data, 18);
	free_env(&data->env);
	free(line);
	exit (1);
}

void	create_heredoc(t_data *data, t_token *token, int *fds)
{
	char	*line;

	line = NULL;
	while (ft_strcmp(line, token->next->str))
	{
		if (line)
			free(line);
		line = readline("> ");
		if (line == NULL
			|| !ft_strcmp(line, token->next->str))
			get_out_of_heredoc(data, token, line);
		else
		{
			line = check_for_var(data, line, 1);
			write(fds[1], &line, ft_strlen(line));
			write(fds[1], "\n", 1);
		}
	}
	data->check_hdc = 1;
	data->fd_in = fds[1];
	close(fds[0]);
	close(fds[1]);
	free_and_close_data(data, 50);
	free_env(&data->env);
	free(line);
	exit (1);
}

void	fork_heredoc(t_data *data, t_token *token)
{
	int		fds[2];
	int		status;
	pid_t	child;

	if (pipe(fds) < 0)
		return (perror("pipe error on heredoc"));
	child = fork();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (child == 0)
	{
		redir_hd(data);
		create_heredoc(data, token, fds);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(child, &status, 0);
	redir(data);
}

void	check_heredoc(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		if (tmp->type == 7)
		{
			fork_heredoc(data, tmp);
		}
		tmp = tmp->next;
	}
	return ;
}
