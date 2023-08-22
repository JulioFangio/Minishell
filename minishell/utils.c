/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:48:15 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 14:48:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_list	make_list(chqr **tab)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = ft_lentab(tab);
	while (i > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew());
		i--;
	}
	return (pile);
}