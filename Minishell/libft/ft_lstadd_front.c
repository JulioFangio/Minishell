/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:38:10 by juduval           #+#    #+#             */
/*   Updated: 2022/11/18 14:53:48 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(lst) || !(new))
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*lst = NULL;	//un seul pointeur psk il pointe deja sur
							un pointeur dans lstadd_front;
	t_list	*elem1;
	t_list	*new;

	elem1 = ft_lstnew("deux");
	new = ft_lstnew("un");
	ft_lstadd_front(&lst, elem1);
	ft_lstadd_front(&lst, new);

	t_list	*tmp;
	tmp = lst;
	while (tmp)
	{
		printf("%s\n", (char *)tmp -> content);
		tmp = tmp -> next;
	}
	return (0);
//	printf("ptr:%p\n", elem1 -> next); pour recuperer l adresse
}*/
