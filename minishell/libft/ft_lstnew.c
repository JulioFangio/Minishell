/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:07:07 by juduval           #+#    #+#             */
/*   Updated: 2023/08/22 15:05:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!(elem))
		return (NULL);
	elem->type = NULL;
	elem->elem = NULL;
	elem->next = (NULL);
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
