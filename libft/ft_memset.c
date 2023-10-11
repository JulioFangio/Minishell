/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:11 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 18:33:31 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remplit les n premiers octets de la zone mémoire
// pointée par s avec l'octet c.

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}
/*
int main(void)
{
    unsigned char s[] = "rurupolopo";
//	ft_memset(s, 'j', 8);
//	printf("%s\n", s);
//	memset(s, 'u', 8);
//	printf("%s\n", s);
    return (0);
}*/
