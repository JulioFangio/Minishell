/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:23:09 by juduval           #+#    #+#             */
/*   Updated: 2023/09/18 16:59:11 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*copy;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	copy = ft_calloc(size + 1, sizeof(char));
	if (!(s))
		return (NULL);
	size = 0;
	while (s[size])
	{
		copy[size] = s[size];
		size++;
	}
	return (copy);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_strdup(av[1]));
	return (0);
}*/
