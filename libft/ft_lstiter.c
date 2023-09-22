/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:17:34 by juduval           #+#    #+#             */
/*   Updated: 2022/11/18 13:00:27 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lst;
	tmp2 = lst;
	if (lst)
	{
		while (tmp)
		{
			tmp2 = tmp2 -> next;
			(*f)(tmp -> content);
			tmp = tmp2;
		}
	}
}
