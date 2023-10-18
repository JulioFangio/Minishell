/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:22 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/19 18:07:25 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ptr_s1[i] == ptr_s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (ptr_s1[i] - ptr_s2[i]);
}
/*
 int main(void)
{
    unsigned char s1[] = "c";
    unsigned char s2[] = "d";
    size_t n = 1;
    printf("%d\n" ,ft_memcmp(s1, s2, n));
    return (0);
}
*/
