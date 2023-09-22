/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:12:37 by juduval           #+#    #+#             */
/*   Updated: 2022/11/16 18:22:29 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;

	lst = ft_lstnew("0");
	elem1 = ft_lstnew("1");
	elem2 = ft_lstnew("2");
	elem3 = ft_lstnew("3");
	lst -> next = elem1;
	elem1 -> next = elem2;
	elem2 -> next = elem3;
	elem3 -> next = NULL;
	elem1 = ft_lstlast(elem1);
	printf("%s\n", (char *)elem1 -> content);
	return (0);
}*/
