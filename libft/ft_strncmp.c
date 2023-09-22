/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:38 by juduval           #+#    #+#             */
/*   Updated: 2022/11/07 11:12:38 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	if ((s1[i] - s2[i]) < -127)
		return ((s1[i] - s2[i]) * -1);
	return (s1[i] - s2[i]);
}
/*
int main(void)
{
    const char s1[] = "jul";
    const char s2[] = "juv";
    size_t n = 3;

    printf("%d\n", ft_strncmp(s1, s2, n));
    return (0);
}*/
