/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:13 by juduval           #+#    #+#             */
/*   Updated: 2023/10/26 14:42:07 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*_heredoc(void)
{
	char	*prompt;

	prompt = ft_strdup("> ");
	return (prompt);
}

void	get_out_of_heredoc(t_data *data, t_token *token, char *line, int fd)
{
	if (line == NULL)
	{
		ft_putstr_fd("warning: here-document delimited", 2);
		ft_putstr_fd(" by end-of-file (wanted `", 2);
		ft_putstr_fd(token->next->str, 2);
		ft_putendl_fd("')", 2);
	}
	data->check_hdc = 1;
	close(fd);
	free(data->hdcdoc);
	free_and_close_data(data, 18);
	free_env(&data->env);
	free(line);
	exit (1);
}

void	create_heredoc(t_data *data, t_token *token)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(token->next->str, O_CREAT | O_RDWR | O_TRUNC, 0777);
	data->hdcfd = fd;
	data->hdcdoc = ft_strdup(token->next->str);
	while (ft_strcmp(line, token->next->str))
	{
		if (line)
			free(line);
		line = readline("> ");
		if (line == NULL
			|| !ft_strcmp(line, token->next->str))
			get_out_of_heredoc(data, token, line, fd);
		else
		{
			line = check_for_var(data, line, 1);
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
	}
}

void	fork_heredoc(t_data *data, t_token *token)
{
	int			status;
	pid_t		child;

	child = fork();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (child == 0)
	{
		redir_hd(data);
		create_heredoc(data, token);
	}
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
