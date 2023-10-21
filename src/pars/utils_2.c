/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:34:13 by juduval           #+#    #+#             */
/*   Updated: 2023/10/21 17:25:48 by jaristil         ###   ########.fr       */
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

static t_tronc	*ft_trclast(t_tronc *tmp)
{
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	ft_trc_add_back(t_tronc **tronc, t_tronc *new)
{
	t_tronc	*last;
	t_tronc	**tmp;

	tmp = tronc;
	if (tmp)
	{
		if (*tmp)
		{
			last = ft_trclast(*tmp);
			last->next = new;
		}
		else
			*tmp = new;
	}
}

static char	*troncate(char *str)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_strlen(str);
	if ((len - 2) == 0)
		return (NULL);
	res = ft_calloc(len + 1, sizeof(char));
	while (i < len - 1)
	{
		res[j] = str[i];
		i++;
		j++;
	}
	return (res);
}

static t_tronc	*ft_troncnew(char *str)
{
	t_tronc	*elem;

	elem = malloc(sizeof(t_tronc));
	if (!(elem))
		return (NULL);
	if (str[0] == '"' || str[0] == '\'')
		elem->str = troncate(str);
	else
		elem->str = ft_strdup(str);
	elem->nb = 1;
	if (str[0] == '\'')
		elem->nb = 0;
	elem->next = (NULL);
	return (elem);
}

static int	get_tmp_len(char *str)
{
	int		i;
	char	b;

	i = 0;
	if (str[i] && str[i] != '"' && str[i] != '\'')
	{
		while (str[i] && str[i] != '"' && str[i] != '\'')
			i++;
	}
	else if (str[i] && (str[i] == '"' || str[i] == '\''))
	{
		b = str[i];
		i++;
		while (str[i] && str[i] != b)
			i++;
		i++;
	}
	return (i);
}

static void	fill_tmp(char *tmp, char *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tmp[i] = tab[i];
		i++;
	}
	return ;
}

static void	free_tronc(t_tronc *tronc)
{
	t_tronc	*tmp;

	while (tronc)
	{
		tmp = tronc->next;
		if (!tronc->str)
		{
			tronc->str = ft_memdel(tronc->str);
		}
		tronc = ft_memdel(tronc);
		tronc = tmp;
	}
}

static char	*join_tronc(t_data *data, t_tronc *tronc)
{
	char	*res;
	char	*join;
	char	*join2;
	t_tronc	*tmp;

	res = NULL;
	tmp = tronc;
	while (tmp)
	{
		join2 = check_for_var(data, tmp->str, tmp->nb);
		join = ft_strjoin(res, join2);
		free(res);
		free(join2);
		res = join;
		tmp = tmp->next;
	}
	free_tronc(tronc);
	// printf("le res est = %s\n", res);
	return (res);
}

char	*tronc_optn(t_data *data, char *tab, int nb)
{
	t_tronc	*tronc;
	char	*tmp;
	int		len;
	int		i;
	int		llen;

	i = 0;
	len = 0;
	tronc = NULL;
	llen = ft_strlen(tab);
	(void)data;
	(void)nb;
	while (i < llen)
	{	
		len = get_tmp_len(tab + i);
		tmp = ft_calloc(len + 1, sizeof(char));
		fill_tmp(tmp, tab + i, len);
		i += len;
		ft_trc_add_back(&tronc, ft_troncnew(tmp));
		free(tmp);
	}
	return (join_tronc(data, tronc));
}

//coucou"ca va $USER"'oui et toi'

// char	*tronc_optn(t_data *data, char *tab, int nb)
// {
// 	int		len;
// 	int		i;
// 	int		j;
// 	char	*tronc;

// 	i = 1;
// 	j = 0;
// 	len = ft_strlen(tab);
// 	if (len == 2)
// 		return (NULL);
// 	tronc = ft_calloc(len + 1, sizeof(char));
// 	if (!tronc)
// 		return (NULL);
// 	while (i < len - 1)
// 	{
// 		tronc[j] = tab[i];
// 		i++;
// 		j++;
// 	}
// 	return (check_for_var(data, tronc, nb));
// }

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