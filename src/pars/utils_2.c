/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:34:13 by juduval           #+#    #+#             */
/*   Updated: 2023/10/14 14:33:50 by juduval          ###   ########.fr       */
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

char	*tronc_optn(t_data *data, char *tab, int nb)
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
	return (check_for_var(data, tronc, nb));
}

static int	ft_strcmp_env(const char *s1, const char *s2)
{
	int	i;
	int	j;

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

char	*pick_env(t_data *data, char *tab)
{
	t_env	*tmp;
	char	*res;

	tmp = data->env;
	while (tmp)
	{
		if (!ft_strcmp_env(tab, tmp->value))
		{
			res = extract_env_value(tmp->value);
			return (res);
		}
		tmp = tmp->next;
	}
	return (tab);
}
