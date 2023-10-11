/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:42 by jaristil          #+#    #+#             */
/*   Updated: 2022/12/12 18:01:21 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tmp;

	tmp = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((tmp / nmemb) != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
