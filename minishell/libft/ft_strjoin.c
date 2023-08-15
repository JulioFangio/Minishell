/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:41:46 by juduval           #+#    #+#             */
/*   Updated: 2022/11/14 16:57:25 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l_s1;
	size_t	l_s2;
	char	*ns;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	ns = malloc(((l_s1 + l_s2) + 1) * sizeof(char));
	if (!(ns))
		return (NULL);
	ft_strcpy(ns, s1);
	ft_strcpy(ns + l_s1, s2);
	return (ns);
}
/*
int	main(void)
{
	char const	s1[] = "au bal";
	char const	s2[] = " au bal masque owe owe";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
