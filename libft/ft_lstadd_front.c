/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:21 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/15 20:17:23 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int main(void)
{
	t_list	*lst = NULL;
	t_list	*one;
//	t_list	*two;
//	t_list	*tmp;
	one = ft_lstnew("");
//	one = NULL;
//	two = ft_lstnew("Jules tu bourres");
	ft_lstadd_front(&lst, NULL);
	
//	while (one->next)
//	{
		printf("%s\n", (char *)one->content);
//		one = one->next;
//	}
//	tmp = one;
	return (0);
}*/
