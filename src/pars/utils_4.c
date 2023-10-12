/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:10:14 by juduval           #+#    #+#             */
/*   Updated: 2023/10/12 17:52:03 by juduval          ###   ########.fr       */
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

char	*keep_spaces(char *line)
{
	char	*res;
	int		i;
	char	b;

	i = 0;
	printf("line = %s et lenline = %zu\n", line, ft_strlen(line));
	res = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	while (line[i])
	{
		if ((line[i] == 34 || line[i] == 39))
		{
			b = line[i];
			res[i] = line[i];
			i++;
			while (line[i] && line[i] != b)
			{
				if (line[i] == 32 || (line[i] >= 9 && line[i] <= 13))
					res[i] = '_';
				else
					res[i] = line[i];
				i++;
			}
		}
		else
		{
			res[i] = line[i];
			i++;
		}
	}
	return (res);
}

char	*remake_line(char *line, int n, int l)
{
	char	*res;
	// char	*res2;
	// char	*res3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc(l + n + 1, sizeof(char));
	if (!res)
		return (NULL);
	res = make_spaces(line, res, 0, (l + n));
	// res2 = remove_spaces(res, i, j);
	// res3 = keep_spaces(res);
	// free(res);
	// free(res2);
	return (res);
}

char	*ft_dupquotes(const char *str, char q)
{
	int		size;
	char	*res;
	int		b;

	size = 1;
	while (str[size] && str[size] != q)
		size++;
	b = size + 1;
	res = ft_calloc(size + 2, sizeof(char));
	size = 0;
	while (size < b)
	{
		res[size] = str[size];
		size++;
	}
	return (res);
}

void	recuperate_fds(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		if (tmp->type >= 4 && tmp->type <= 6)
			tmp->fd = open(tmp->next->str, O_CREAT | O_RDWR, 0644);
		tmp = tmp->next;
	}
	tmp = data->token;
	while (tmp)
	{
		printf(" str = %s / type = %d / fd = %d\n", tmp->str, tmp->type, tmp->fd);
		tmp = tmp->next;
	}
}

//quand les quotes ne sont pas fermantes la premieres fois erreur invalid 
// read of size mais pas les autres fois

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab[i]);
// 	free(tab);
// }
