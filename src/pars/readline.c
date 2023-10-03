/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:13:43 by juduval           #+#    #+#             */
/*   Updated: 2023/09/27 13:07:51 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_split(char *line)
{
	char	**tab;
	char	*nline;
	int		n;
	int		l;

	l = ft_strlen(line);
	n = whole_count(line);
	nline = remake_line(line, n, l);
	if (!check_line(line))
	{
		free (line);
		free (nline);
		return ((char **)1);
	}
	tab = split_mini(nline, ' ');
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
