/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:13:43 by juduval           #+#    #+#             */
/*   Updated: 2023/10/10 14:29:54 by juduval          ###   ########.fr       */
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
	if (!check_line(line))
	{
		free (line);
		return ((char **)1);
	}
	nline = remake_line(line, n, l);
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
	// char	*dir;
	char	*prompt;

	// dir = getcwd(NULL, 0);
	// if (dir)
	// {
		prompt = ft_strjoin("", "Minishell$ ");
		// free(dir);
		return (prompt);
	// }
	// else
	// 	return (NULL);
}
