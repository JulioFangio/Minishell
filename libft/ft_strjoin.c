/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:36:50 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:06 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_join(char *join, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	join = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!(join))
		return (NULL);
	if ((ft_strlen(s1) + ft_strlen(s2) > 0))
		fill_join(join, s1, s2);
	return (join);
}

/*int	main(int ac, char **av)
{
	(void)ac;
	printf("%s\n" ,ft_strjoin(av[1], av[2]));
	return (0);
}*/
