/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:41:43 by jaristil          #+#    #+#             */
/*   Updated: 2023/01/20 18:25:34 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*one;
	t_list	*two;

	one = ft_lstnew("juventz");
	two = ft_lstnew("jules");
//	one -> next = two;
//	two -> next = NULL;
	ft_lstadd_front(&lst, one);
	ft_lstadd_front(&one, two);
	printf("%d\n", ft_lstsize(lst));
	return (0);
}*/
