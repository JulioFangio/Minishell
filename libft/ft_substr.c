/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:35 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/19 18:11:44 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Alloue et retourne a string from s.
// begin at index ’start’ where sizemax = len

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(s);
	i = 0;
	if (start + len > len_src)
		len = len_src - start;
	if (!s || start >= len_src)
		return (ptr = ft_calloc(1, 1));
	ptr = malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (NULL);
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int main(void)
{
    const char  s[] = "Mozilla";
    unsigned int	start = 8;
    size_t  len = 9;
    printf("%s\n", ft_substr(s, n, len));
    return (0);
}
*/
