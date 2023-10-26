/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:40 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/11 14:39:43 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_char_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ptr_s1;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_char_set(s1[start], set))
		start++;
	while (end > start && ft_char_set(s1[end - 1], set))
		end--;
	ptr_s1 = malloc(sizeof(char) * (end - start + 1));
	if (!(ptr_s1))
		return (NULL);
	while (end > start)
		ptr_s1[i++] = s1[start++];
	ptr_s1[i] = '\0';
	return (ptr_s1);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("%s\n" ,ft_strtrim(av[1], av[2]));
	return (0);
}*/
