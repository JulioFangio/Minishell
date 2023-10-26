/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:49:31 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/18 13:54:32 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
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
	printf("%s\n", (char *)lst->content);
	return (0);
}*/
