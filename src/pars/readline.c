/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:13:43 by juduval           #+#    #+#             */
/*   Updated: 2023/10/17 16:40:58 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_line(char *line)
{
	if (!check_quotes(line))
	{
		printf("%s: syntax error\n", line);
		return (0);
	}
	return (1);
}

char	**get_split(t_data *data, char *line)
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
		free_and_close_data(data, 0);
		free_env(data->env);
		exit (1);
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
		printf("exit DEBUG\n");
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
