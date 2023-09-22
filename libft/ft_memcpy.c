/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:00 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 19:36:06 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copie n octets depuis la zone mémoire src vers la zone mémoire dest.
// Les deux zones ne doivent pas se chevaucher.

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
    unsigned char dest[] = "juju";
    unsigned char src[] = "";
    size_t n = 2 ;
    printf("%s\n" ,ft_memcpy(dest, src, n));
    return (0);
}*/
