/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:52:51 by juduval           #+#    #+#             */
/*   Updated: 2022/11/18 15:40:42 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	if (lst)
	{
		if (*lst)
		{
			while (tmp)
			{
				tmp2 = tmp2 -> next;
				ft_lstdelone(tmp, del);
				tmp = tmp2;
			}
			*lst = NULL;
		}
	}
}
