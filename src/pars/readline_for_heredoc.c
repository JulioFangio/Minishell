/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_for_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:39:22 by juduval           #+#    #+#             */
/*   Updated: 2023/10/05 18:02:47 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char	**get_split_heredoc(char *line)
// {
// 	char	**tab;
// 	char	*nline;
// 	int		n;
// 	int		l;

// 	l = ft_strlen(line);
// 	n = whole_count(line);
// 	nline = remake_line(line, n, l);
// 	if (!check_line(line))
// 	{
// 		free (line);
// 		free (nline);
// 		return ((char **)1);
// 	}
// 	tab = split_mini(nline, ' ');
// 	free(line);
// 	free (nline);
// 	return (tab);
// }

char	*ft_readline_heredoc(void)
{
	char	*line;
	char	*prompt;

	prompt = get_prompt_heredoc();
	line = readline(prompt);
	free(prompt);
	if (line == NULL)
	{
		printf("exit\n");
		return (NULL);
	}
	return (line);
}


char	*get_prompt_heredoc(void)
{
	char	*prompt;

	prompt = ft_strdup("> ");
	return (prompt);
}
