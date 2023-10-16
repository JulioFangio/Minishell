/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:04:40 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 20:10:29 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// compare que les n (au plus) premiers caractères de s1 et s2

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && (i < n))
		i++;
	if (i == n)
		return (0);
	if (s1[i] - s2[i] < -127)
		return ((s1[i] - s2[i]) * -1);
	return (s1[i] - s2[i]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main(int ac, char **av)
{
    (void)ac;
    printf("%d\n" ,ft_strncmp(av[1], av[2], atoi(av[3])));
    return (0);
}
*/
