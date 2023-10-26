/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:25 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/15 14:01:02 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return la longueur de la chaine que stlrcat a voulu creer.
// Si return > size, alors il y a leaks.

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i = 0;
	j = len_dest;
	if (!size)
		return (len_src);
	if (j > size)
		return (len_src + size);
	while (src && src[i] && (i + j) < (size - 1))
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = 0;
	return (len_dest + len_src);
}
/*
int main(void)
{
    char dest[] = "This is ";
    char src[] = "a potentially long string";
    size_t  size = 16;
    printf("%ld\n", ft_strlcat(dest, src, size));
    return(0);
}*/
