/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:44 by juduval           #+#    #+#             */
/*   Updated: 2022/11/07 11:12:44 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] && to_find[j] && i + j < n && s1[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
int main(void)
{
    char    s1[] = "Call of duty";
    char    to_find[] = "of";
    size_t  n = 5;
    printf("%s\n", ft_strnstr(s1, to_find, n));
//	printf("%s\n", strnstr(s1, to_find, n));
    return (0);
}*/
