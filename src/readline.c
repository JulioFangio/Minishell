/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:16 by jaristil          #+#    #+#             */
/*   Updated: 2023/08/29 18:08:45 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_prompt(void)
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

static char	*ft_readline(void)
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

static char	**get_split(void)
{
	char	**tab;
	int		i;

	i = -1;
	tab = ft_split(ft_readline(), ' ');
	while (tab[++i])
		printf("%s\n", tab[i]);
	return (tab);
}

void	run_shell(void)
{
	using_history();
	while (1)
		get_split();
	rl_clear_history();
}
