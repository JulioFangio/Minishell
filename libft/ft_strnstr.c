/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:46 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 19:57:12 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + j] == s2[j] && s1[i + j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
		j = 0;
	}
	return (0);
}
/*
int main(void)
{
    char s1[] = "call of duty";
    char s2[] = "of";
    size_t n = 5;
    printf("%s\n" ,ft_strnstr(s1, s2, n));
	printf("%s\n", strnstr(s1, s2, n));
    return (0);
}*/
