/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:11:54 by jaristil          #+#    #+#             */
/*   Updated: 2023/01/18 13:31:37 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*one;
	t_list	*two;

	one = ft_lstnew("Best");
	two = ft_lstnew("jules");
	ft_lstadd_front(&lst, one);
//	ft_lstadd_front(&one, two);
	two -> next = one;
	one -> next = NULL;
	lst = ft_lstlast(lst);
	printf("%s\n", (char *)lst->content);
	return (0);
}*/
