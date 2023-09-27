/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:22:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/27 17:22:53 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// create pipe from in to take all the input write in the << data->pipefd[0]
// and  give the out of pipe to write data->pipefd[1]
void	redir_heredoc(t_data *data, t_token *token)
{
	char	*hd_file;
	int		fd;

	unlike(".heredoc");
	fd = open(".heredoc", O_WRONLY | O_CREAT);
	// verifier flags
	if (fd < 0 || !(token->str) || ft_strlen(token->str) == 0)
	{
		ft_putstr_fd(token->str, STDERR);
		ft_putendl_fd(ERR_OPEN, STDERR);
		data->err_redir = FAILURE;
		data->result = FAILURE;
		return ;
	}
	// hd_file = // ce que ju recup sous forme de *str(token->str);
	if (!hd_file)
		ft_putstr_fd("", fd);
		// it write an empty stirng inside the file .heredoc
		// so jules has to return NULL if he can't find occurence
	else
		ft_putstr_fd(hd_file, fd);
	free(hd_file);
	close(fd);
	open_heredoc(data);
}
