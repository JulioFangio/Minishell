/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:00:46 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/08 15:15:03 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*strcpy_heredoc(char *dest, char *src)
{
	ft_memcpy(dest, src, ft_strlen(src)+ 1);
	return (dest);
}

char	*strjoin_heredoc(char *s1, char *s2)
{
	char	*str;
	char	ptr;
	size_t	len;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ptr = str;
	ptr = strcpy_heredoc(ptr, s1);
	ptr += ft_strlen(s1);
	ptr = strcpy_heredoc(ptr, s2);
	return (free(s1), free(s2), str);
}

char	*get_input_heredoc(char *limiter)
{
	char	*line;
	char	*input;
	char	*input_tmp;

	input = NULL;
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			ft_printf("warning: here-document delimited by end-of-file");
			ft_printf(" (wanted `%s')\n", limiter);
			return (input);
		}
		else if (ft_strcmp(line, limiter) == 0)
			return (free(line), input);
		printf("This is my input :%s\n This is my line : %s\n", input, line);
		input_tmp = strjoin_heredoc(input, line);
		input = ft_strjoin(input_tmp, "\n");
		free(input_tmp);
	}
}

void	open_heredoc(t_data *data)
{
	data->fd_in = open(".heredoc", O_RDONLY);
	if (data->fd_in < 0)
	{
		ft_putstr_fd(ERR_OPEN, STDERR);
		data->result = FAILURE;
		data->err_redir = FAILURE;
		return ;
	}
	unlink(".heredoc");
	dup2(data->fd_in, STDIN);
}

void	redir_heredoc(t_data *data, t_token *token)
{
	char	*hd_input;
	int		fd;

	unlink(".heredoc");
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0 || !(token->str) || ft_strlen(token->str) == 0)
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(ERR_OPEN, STDERR);
		data->err_redir = FAILURE;
		data->result = FAILURE;
		return ;
	}
	hd_input = get_input_heredoc(token->str);
	check_for_var(hd_input, 1);
	if (!hd_input)
		ft_putstr_fd("", fd);
	else
		ft_putstr_fd(hd_input, fd);
	free(hd_input);
	close(fd);
	open_heredoc(data);
}
