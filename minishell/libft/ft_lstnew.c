/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:07:07 by juduval           #+#    #+#             */
/*   Updated: 2022/11/15 17:35:31 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!(elem))
		return (NULL);
	elem -> content = content;
	elem -> next = (NULL);
	return (elem);
}
/*
int	main(void)
{
	t_list	*elem1;

	elem1 = ft_lstnew("c est trop dla bouz");
	printf("%s\n", (char *)elem1 -> content);
	return (0);
}*/
