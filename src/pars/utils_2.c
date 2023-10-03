/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:34:13 by juduval           #+#    #+#             */
/*   Updated: 2023/09/27 13:16:21 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

int	how_long(char *line, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (i > 0 && line[i] == c && line[i - 1] != 32 && line[i - 1] != c)
			count++;
		else if (i < ft_strlen(line) && line[i] == c
			&& line[i + 1] != 32 && line[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

char	*tronc_optn(char *tab, int nb)
{
	int		len;
	int		i;
	int		j;
	char	*tronc;

	i = 1;
	j = 0;
	len = ft_strlen(tab);
	if (len == 2)
		return (NULL);
	tronc = ft_calloc(len + 1, sizeof(char));
	if (!tronc)
		return (NULL);
	while (i < len - 1)
	{
		if (tab[i] == '_')
			tronc[j] = 32;
		else
			tronc[j] = tab[i];
		i++;
		j++;
	}
	return (check_for_var(tronc, nb));
}

char	*pick_env(char *tab)
{
	extern char	**environ;
	int			i;
	char		*res;

	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(tab + 1, environ[i], ft_strlen(tab) - 1))
		{
			res = extract_env_value(environ[i]);
			return (res);
		}
		i++;
	}
	return (tab);
}

// char	*keep_spaces(char *line)
// {
// 	char	*res;
// 	int		i;
// 	char	b;

// 	i = 0;
// 	res = ft_calloc(ft_strlen(line) + 1, sizeof(char));
// 	while (line[i])
// 	{
// 		if (line[i] == 34 || line[i] == 39)
// 		{
// 			b = line[i];
// 			while (line[i] != b)
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