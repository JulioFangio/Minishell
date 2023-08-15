/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:59:47 by juduval           #+#    #+#             */
/*   Updated: 2022/11/19 17:29:39 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Itère sur la liste ’lst’ et applique la fonction
//’f ’au contenu de chaque élément. Crée une nouvelle
//liste résultant des applications successives de
//’f’. La fonction ’del’ est là pour détruire le
//contenu d’un élément si nécessaire.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nelem;
	t_list	*nlist;

	nlist = NULL;
	if (!(lst) || !(f) || !(del))
		return (NULL);
	while (lst)
	{
		nelem = ft_lstnew(f(lst -> content));
		if (!(nelem))
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, nelem);
		lst = lst -> next;
	}
	return (nlist);
}
