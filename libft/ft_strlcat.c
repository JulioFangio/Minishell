/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:18 by juduval           #+#    #+#             */
/*   Updated: 2022/11/07 11:12:18 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l_src;
	size_t	l_dest;

	l_src = ft_strlen(src);
	l_dest = ft_strlen(dest);
	i = 0;
	j = l_dest;
	if (size == 0)
		return (l_src);
	if (size < l_dest)
		return (l_src + size);
	while (src && src[i] && i + l_dest < (size - 1))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (l_dest + l_src);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
    char dst[7] = "000";
    char src[7] = "123";
    char dst1[7] = "000";
    char src1[7] = "123";
    printf("my: return:%d, dest:%s\n",ft_strlcat(dst,src,8), dst);
    printf("real: return:%d, dest:%s\n\n",strlcat(dst1,src1,8), dst1);

    char dst2[7] = "";
    char src2[7] = "123";
    char dst3[7] = "";
    char src3[7] = "123";
    printf("my: return:%d, dest:%s\n", ft_strlcat(dst2,src2,2), dst2);
    printf("real: return:%d, dest:%s\n\n", strlcat(dst3,src3,2), dst3);

    char dst4[7] = "000";
    char src4[7] = "";
    char dst5[7] = "000";
    char src5[7] = "";
    printf("my: return:%d, dest:%s\n", ft_strlcat(dst4,src4,7), dst4);
    printf("real: return:%d, dest:%s\n\n", strlcat(dst5,src5,7), dst5);

    char dst6[7] = "a";
    char src6[26] = "lorem ipsum dolor sit amet";
    char dst7[7] = "a";
    char src7[26] = "lorem ipsum dolor sit amet";
    printf("my: return:%d, dest:%s\n", ft_strlcat(dst6,src6,1), dst6);
    printf("real: return:%d, dest:%s\n\n", strlcat(dst7,src7,1), dst7);
}*/
