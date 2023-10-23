/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:13:43 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:25:47 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_line(char *line)
{
	if (!check_quotes(line))
	{
		ft_putstr_fd(line, 2);
		ft_putendl_fd(": syntax error", 2);
		return (0);
	}
	return (1);
}

char	**get_split(char *line)
{
	char	**tab;
	char	*nline;
	int		n;
	int		l;
	int		i;

	i = -1;
	if (!check_line(line))
	{
		free (line);
		return (NULL);
	}
	l = ft_strlen(line);
	n = whole_count(line);
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
		ft_putendl_fd("exit", 1);
		return (NULL);
	}
	add_history(line);
	return (line);
}

char	*get_prompt(void)
{
	char	*prompt;

	prompt = ft_strjoin("", "Minishell$ ");
	return (prompt);
}
