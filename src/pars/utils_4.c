/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:10:14 by juduval           #+#    #+#             */
/*   Updated: 2023/09/22 16:28:50 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_end(char *line, int i, char c)
{
	while (line[i] && line[i] == c)
		i++;
	while (line[i] && line[i] != c)
		i++;
	while (line[i] && line[i] == c)
		i++;
	return (i);
}


// char	*keep_spaces(char *line)
// {
// 	char	*res;
// 	int		i;
// 	int		b;

// 	i = 0;
// 	res = ft_calloc(ft_strlen(line) + 1, sizeof(char));
// 	while (line[i])
// 	{
// 		if (line[i] == 34 || line[i] == 39)
// 		{
// 			b = check_end(line, i, line[i]);
// 			while (i < b)
// 			{
// 				if (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))
// 					res[i] = '`';
// 				else
// 					res[i] = line[i];
// 				i++;
// 			}
// 			continue ;
// 		}
// 		res[i] = line[i];
// 		i++;
// 	}
// 	return (res);
// }

char	*keep_spaces(char *line)
{
	char	*res;
	int		i;
	char	b;

	i = -1;
	res = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	while (line[++i])
	{
		if (line[i] == 34 || line[i] == 39)
		{
			b = line[i];
			res[i] = line[i];
			i++;
			while (line[i] != b)
			{
				if (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))
					res[i] = '`';
				else
					res[i] = line[i];
				i++;
			}
		}
		res[i] = line[i];
	}
	return (res);
}

char	*remake_line(char *line, int n, int l)
{
	char	*res;
	char	*res2;
	char	*res3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc(l + n + 1, sizeof(char));
	if (!res)
		return (NULL);
	res = make_spaces(line, res, 0, 0);
	res2 = remove_spaces(res, i, j);
	res3 = keep_spaces(res2);
	free(res);
	free(res2);
	return (res3);
}

void	free_lst(t_token *cmd)
{
	t_token	*tmp;
	int		i;

	i = 0;
	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->elem);
		free(tmp->type);
		free(tmp);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}
