/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:53 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 17:48:26 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// renvoie un pointeur sur la last occurrence du caractère c dans la chaîne s

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			ptr = (char *)&s[i];
		i++;
	}
	if (s[i] == (const char)c)
		ptr = (char *)&s[i];
	return (ptr);
}
/*
int main(int ac, char **av)
{
    (void)ac;
    printf("%s\n" ,ft_strrchr(av[1], av[2]));
    return (0);
}*/
