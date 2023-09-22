/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:40:46 by juduval           #+#    #+#             */
/*   Updated: 2022/11/18 12:41:23 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkset(char c, char const *set)
{
	int	i;

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
	char	*ns;
	int		b1;
	int		b2;
	int		i;

	b1 = 0;
	b2 = ft_strlen(s1);
	while (s1[b1] && ft_checkset(s1[b1], set))
		b1++;
	while (b2 > b1 && ft_checkset(s1[b2 - 1], set))
		b2--;
	ns = malloc((b2 - b1 + 1) * sizeof(char));
	if (!(ns))
		return (NULL);
	i = 0;
	while (b2 > b1)
	{
		ns[i] = s1[b1];
		i++;
		b1++;
	}
	ns[i] = '\0';
	return (ns);
}
/*
int	main(void)
{
	char	s1[] = "sssssiasssssssss";
	char	set[] = "s";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
