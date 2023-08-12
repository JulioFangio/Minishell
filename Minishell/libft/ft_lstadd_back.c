/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:47:59 by juduval           #+#    #+#             */
/*   Updated: 2022/11/19 19:02:12 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last -> next = new;
		}
		else
			*lst = new;
	}
}
/*
int main(void)
{
    t_list    *lst;
    t_list    *one;
    t_list    *two;
    t_list    *three;
    char    *str1;
    char    *str2;
    char    *str3;

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
