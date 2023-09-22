/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:25 by juduval           #+#    #+#             */
/*   Updated: 2022/11/07 11:12:25 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (count);
}
/*
#include <string.h>

int main(void)
{
    char    dest1[] = "jules";
    const char  src1[] = "";
    size_t  size1 = 5;
	char    dest[] = "jules";
    const char  src[] = "";
    size_t  size = 5;

    printf("return ; %d dest: %d\n", ft_strlcpy(dest, src, size), dest);
	printf("return : %d dest : %d\n", strlcpy(dest1, src1, size1), dest);
    return (0);
}*/
