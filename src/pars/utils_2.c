/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:34:13 by juduval           #+#    #+#             */
/*   Updated: 2023/10/12 16:45:23 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skip_quotes(char *line, size_t i)
{
	char	b;

	if (line[i] == 34 || line[i] == 39)
	{
		b = line[i];
		i++;
		while (line[i] && line[i] != b)
			i++;
		return (i);
	}
	return (i);
}

int	how_long(char *line, char c, int count, size_t i)
{
	char	b;
	size_t	len;

	len = ft_strlen(line);
	while (line[i] && i < len)
	{
		if (line[i + 1] && (line[i] == '"' || line[i] == '\''))
		{
			b = line[i];
			i++;
			while (line[i] && i < len && line[i] != b)
				i++;
		}
		else if (line[i] == c && i < len
			&& ((i > 0 && line[i - 1] != 32 && line[i - 1] != c)
				|| (line[i + 1] && line[i + 1] != 32 && line[i + 1] != c)))
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
		tronc[j] = tab[i];
		i++;
		j++;
	}
	return (check_for_var(tronc, nb));
}

static int	ft_strcmp_env(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (s2[i] != '=' && s1[j] && s2[i] && s1[j] == s2[i])
	{
		i++;
		j++;
	}
	if (s2[i] == '=')
		return (0);
	return (1);
}

char	*pick_env(char *tab)
{
	extern char	**environ;
	int			i;
	char		*res;

	i = 0;
	printf("var = %s\n", tab);
	while (environ[i])
	{
		if (!ft_strcmp_env(tab, environ[i]))
		{
			res = extract_env_value(environ[i]);
			return (res);
		}
		i++;
	}
	return (tab);
}


// char	*make_spaces(char *line, char *res, size_t i, int j)
// {
// 	size_t	n;

// 	n = 0;
// 	while (line[i])
// 	{
// 		printf("la liiiiiiiiiiiiiigne ============= %s\n", line);
// 		n = skip_quotes(line, i);
// 		while (i < n)
// 		{
// 			res[j] = line[i];
// 			j++;
// 			i++;
// 		}
// 		if (is_sep(line[i]) && ((line[i - 1] && !is_sep(line[i - 1])
// 					&& line[i - 1] != 32) || (line[i + 1]
// 					&& !is_sep(line[i + 1]) && line[i + 1] != 32)))
// 		{
// 			res[j] = ' ';
// 			j++;
// 			res[j] = line[i];
// 		}
// 		else
// 			res[j] = line[i];
// 		j++;
// 		i++;
// 	}
// 	printf("res ============= %s\n", res);
// 	return (res);
// }


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