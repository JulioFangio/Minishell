/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:36:39 by juduval           #+#    #+#             */
/*   Updated: 2022/11/19 19:04:38 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*lst = NULL;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;

	elem1 = ft_lstnew("1");
	elem2 = ft_lstnew("2");
	elem3 = ft_lstnew("3");
	ft_lstadd_front(&lst, elem1);
	elem1 -> next = elem2;
	elem2 -> next = elem3;
	elem3 -> next = NULL;
	printf("%d\n", ft_lstsize(lst));
	return (0);
}*/
