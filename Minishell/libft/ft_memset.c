/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:05 by juduval           #+#    #+#             */
/*   Updated: 2022/11/07 11:12:05 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
    char    s[] = "aaa";
    int 	c = 98;
    size_t  n = 3;

	ft_memset(s, c, n);
    printf("%s\n", s);
	memset(s, c, n);
	printf("%s\n", s);
    return (0);
}*/
