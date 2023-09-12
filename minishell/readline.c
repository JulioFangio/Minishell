/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:13:43 by juduval           #+#    #+#             */
/*   Updated: 2023/09/12 10:55:15 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_split(void)
{
	char	**tab;
	char	*line;
	char	*nline;
	int		n;
	int		l;

	line = ft_readline();
	if (line == NULL)
		return (NULL);
	l = ft_strlen(line);
	n = whole_count(line);
	nline = remake_line(line, n, l);
	if (!check_line(line))
	{
		printf("%s: command not found\n", line);
		free (line);
		return ((char **)1);
	}
	// printf("la liiiiiiiiigne est = %s\n", nline);
	tab = ft_split(nline, ' ');
	free(line);
	free (nline);
	return (tab);
}

char	*ft_readline(void)
{
	char	*line;
	char	*prompt;

	prompt = get_prompt();
	line = readline(prompt);
	free(prompt);
	if (line == NULL)
	{
		printf("exit\n");
		return (NULL);
	}
	add_history(line);
	return (line);
}

char	*get_prompt(void)
{
	char	*dir;
	char	*prompt;

	dir = getcwd(NULL, 0);
	if (dir)
	{
		prompt = ft_strjoin(dir, "$ ");
		free(dir);
		return (prompt);
	}
	else
		return (NULL);
}

// apres redir c est un mot
// tjrs comandes puis options puis args
// au pipe on recomence le process
// extern char **env;