/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:13:43 by juduval           #+#    #+#             */
/*   Updated: 2023/09/05 19:35:43 by juduval          ###   ########.fr       */
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
	l = ft_strlen(line);
	n = whole_count(line);
	nline = remake_line(line, n, l);
	if (!check_line(line))
	{
		printf("%s: command not found\n", line);
		free (line);
		return (NULL);
	}
	printf("la liiiiiiiiigne est = %s\n", nline);
	tab = ft_split(nline, ' ');
	free (line);
	return (tab);
}

char	*ft_readline(void)
{
	char	*line;
	char	*prompt;

	prompt = get_prompt();
	line = readline(prompt);
	free(prompt);
	if (line)
	{
		add_history(line);
		return (line);
	}
	else
		return (NULL);
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
