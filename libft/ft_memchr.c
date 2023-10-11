/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:16 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/19 18:10:10 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// examine les n 1st octets de la zone mémo pointée par s en cherchant c

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (i < n)
	{
		if (ptr_s[i] == (unsigned char)c)
			return ((unsigned char *)ptr_s + i);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    unsigned char s[] = {'0', '1', '2', '3', '4', '5'};
    int c = '0';
    size_t n = 1;
	printf("%s", (char *) ft_memchr(s, c, n));
    return (0);
}*/
