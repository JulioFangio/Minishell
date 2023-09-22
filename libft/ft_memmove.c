/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:02:33 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 19:34:28 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n--)
			(*(unsigned char *)(dest + n)) = (*(unsigned char *)(src + n));
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int main(void)
{
    unsigned char dest[] = "OldString";
    unsigned char src[] = "NewString";
    size_t n = 9;
    printf("%s\n" ,ft_memmove(dest, src, n));
    return (0);
}*/
