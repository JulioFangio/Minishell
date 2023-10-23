/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:34:13 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 12:36:29 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*troncate(char *str)
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

static int	get_tmp_len(char *str)
{
	int		i;
	char	b;

	i = 0;
	if (str[i] && str[i] != '"' && str[i] != '\'' && str[i] != '$')
	{
		while (str[i] && str[i] != '"' && str[i] != '\'' && str[i] != '$')
			i++;
	}
	else if (str[i] && str[i] == '$')
	{
		i++;
		while (str[i] && str[i] != '"' && str[i] != '\'' && str[i] != '$')
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
