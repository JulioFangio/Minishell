/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:31:39 by juduval           #+#    #+#             */
/*   Updated: 2023/10/23 18:11:53 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *pick_env(t_data *data, char *tab)
{
    t_env    *tmp;
    char    *ntab;
    char    *res;

    tmp = data->env;
    ntab = ft_strjoin(tab, "=");
    while (tmp)
    {
        if (!ft_strncmp(ntab + 1, tmp->value, ft_strlen(ntab + 1)))
        {
            res = extract_env_value(tmp->value);
            free(ntab);
            return (res);
        }
        tmp = tmp->next;
    }
    free(ntab);
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
