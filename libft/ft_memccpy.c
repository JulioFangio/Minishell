/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:09 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/15 14:17:13 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	while (ptr_s[i] != c && i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	if (i < n)
		ptr_d[i] = ptr_s[i];
	if (i == n)
		return (0);
	return (dest + i + 1);
}

/*
int main(void)
{
    unsigned char dest[] = "ruru";
    unsigned char src[] = "vale";
    size_t n = 3 ;
    int c = 'l';
	ft_memccpy(dest, src, c, n);
//  	memccpy(dest, src, c, n);
	printf("%s", dest);
    return (0);
}*/
