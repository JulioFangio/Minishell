/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:32:13 by juduval           #+#    #+#             */
/*   Updated: 2023/10/08 13:18:39 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	create_heredoc(t_token *token, int	*fds, char **tab)
// {
// 	char	*line;

// 	line = NULL;
// 	while (ft_strcmp(line, token->next->str))
// 	{
// 		if (line)
// 			free(line);
// 		line = ft_readline_heredoc();
// 		if (line == NULL)
// 		{
// 			close(fds[0]);
// 			close(fds[1]);
// 			free_tab(tab);
// 			free_lst(token);
// 			exit (1);
// 		}
// 		else
// 		{
// 			printf("t type = %d et tnext type = %d elem = %s\n", token->type, token->next->type, token->next->str);
// 			line = check_for_var(line, 1);
// 			write(fds[1], &line, ft_strlen(line));
// 			write(fds[1], "\n", 1);
// 			token->fd = fds[1];
// 		}
// 	}
// 	free_tab(tab);
// 	free_lst(token);
// 	free(line);
// 	exit (1);
// }

// // pour free correcetment a la fin du heredoc transporter data jusaue dans le child 
// // pour pouvoir tout free en cas d erreur ou de fin du process enfant 
// // mettre un int dans data bouleen pour dire que l on est dans un heredo et changer le comportement de ctrl + c et ctrl + /

// void	fork_heredoc(t_token *token, char **tab)
// {
// 	int		fds[2];
// 	int		status;
// 	pid_t	child;

// 	if (pipe(fds) < 0)
// 		return (perror("pipe error on heredoc"));
// 	child = fork();
// 	if (child == 0)
// 		create_heredoc(token, fds, tab);
// 	close(fds[0]);
// 	// close(fds[1]); a verif !!!!!!!!!!!!!!
// 	waitpid(child, &status, 0);
// }

// void	check_heredoc(t_token *token, char **tab)
// {
// 	t_token	*tmp;

// 	tmp = token;
// 	while (token)
// 	{
// 		if (token->type == 7)
// 			fork_heredoc(token, tab);
// 		token = token->next;
// 	}
// }

// int	count_lines(char *doc)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	fd = open(doc, O_RDONLY);
// 	line = "";
// 	i = 0;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 		{
// 			i++;
// 			free(line);
// 			line = "";
// 		}
// 	}
// 	free(line);
// 	close(fd);
// 	return (i);
// }

// char	**doc_into_tab(char *doc)
// {
// 	int		fd;
// 	int		count;
// 	char	**tab;
// 	int		i;

// 	fd = open(doc, O_RDONLY);
// 	count = count_lines(doc);
// 	tab = ft_calloc(sizeof(char *), count + 1);
// 	i = 0;
// 	while (i < count)
// 	{
// 		tab[i] = get_next_line(fd);
// 		i++;
// 	}
// 	tab[i] = 0;
// 	close (fd);
// 	return (tab);
// }

// //convertir le tab en str joined

// int	add_lentabs(char **tab)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (tab[i])
// 	{
// 		len += ft_strlen(tab[i]);
// 		i++;
// 	}
// 	return (len);
// }

// char	*get_heredoc(int fd)
// {
// 	char	**tab;
// 	char	*res;
// 	int		lt;
// 	int		i;

// 	i = 0;
// 	tab = get_next_line(fd);
// 	lt = ft_lentab(tab);
// 	if (!tab)
// 		return (NULL);
// 	res = ft_calloc(add_lentabs(tab) + lt, sizeof(char));
// 	while (tab[i])
// 	{
// 		res = ft_strjoin(res, tab[i]);
// 		if (i < lt)
// 			res = ft_strjoin(res, "\n");
// 		i++;
// 	}
// 	retunr (res);
// }

	// char	*str;

	// (void)ac;
	// (void)env;
	// str = get_heredoc(open(av[1], O_RDONLY));
	// printf("%s\n", str);
	// return (0);