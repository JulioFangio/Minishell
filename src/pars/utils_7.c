/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:31:39 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 11:37:40 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

t_tronc	*ft_trclast(t_tronc *tmp)
{
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_trc_add_back(t_tronc **tronc, t_tronc *new)
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

t_tronc	*ft_troncnew(char *str)
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
