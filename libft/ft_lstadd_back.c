/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:18:46 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/17 20:51:01 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}
/*
int main(void)
{
	t_list	*lst;
	t_list	*one;
	t_list	*two;
	t_list	*three;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "La cle du succes?";
	str2 = "l'effort, le talent...";
	str3 = "et la chance !";
	one = ft_lstnew(str1);
	two = ft_lstnew(str2);
	three = ft_lstnew(str3);
	lst = NULL;
	ft_lstadd_back(&lst, one);
	ft_lstadd_back(&lst, two);
	ft_lstadd_back(&lst, three);
	while(lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}*/
