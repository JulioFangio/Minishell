/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:19:38 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/11 13:27:00 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*copy;

	i = 0;
	size = ft_strlen(s);
	copy = malloc(sizeof(char) * (size + 1));
	if (!(copy))
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n" ,ft_strdup(argv[1]));
	printf("%s\n" ,strdup(argv[1]));
	return (0);
}*/
