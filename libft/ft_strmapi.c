/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:41:39 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/19 19:56:23 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applique la fonction ’f’ à chaque caractère de la
// chaîne de caractères passée en argument pour créer
// une nouvelle chaîne de caractères
// résultant des applications successives de ’f’.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (NULL);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char const s[] = "Julesjuventz";
}*/
