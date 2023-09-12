/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:37:50 by juduval           #+#    #+#             */
/*   Updated: 2023/09/12 16:48:47 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ns;
	size_t	tmp;

	tmp = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((tmp / nmemb) != size)
		return (NULL);
	ns = malloc(nmemb * size);
	if (!(ns))
		return (NULL);
	ft_bzero(ns, nmemb * size);
	return (ns);
}
