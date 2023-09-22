/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:16 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/10 19:53:22 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// renvoie un pointeur sur la 1st occurrence du caractère c dans la chaîne s

#include    "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(void)
{
    char	s[] = "jules";
	int	c = 'k';
    ft_strchr(s, c);
	printf("%s\n", ft_strchr(s, c));
    return (0);
}*/
