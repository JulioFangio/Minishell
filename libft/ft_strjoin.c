/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:36:50 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/20 23:43:05 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	join = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!(join))
		return (NULL);
	if ((ft_strlen(s1) + ft_strlen(s2) > 0))
	{
		while (s1[i])
		{
			join[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			join[i++] = s2[j];
			j++;
		}
	}
	return (join);
}

/*int	main(int ac, char **av)
{
	(void)ac;
	printf("%s\n" ,ft_strjoin(av[1], av[2]));
	return (0);
}*/
