/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:50 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/19 18:09:16 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	if (!content)
		element->content = NULL;
	element -> content = content;
	element -> next = NULL;
	return (element);
}
/*
int	main(void)
{
	t_list *one;
	
	one = ft_lstnew("Je veux que les numeros uns autour de moi");
	printf("%s\n", (char *)one -> content);
	return (0);
}*/
