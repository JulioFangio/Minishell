/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:19:06 by jaristil          #+#    #+#             */
/*   Updated: 2022/11/13 20:54:27 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nmb;

	nmb = n;
	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	if (nmb < 0)
	{
		str[0] = '-';
		nmb = -nmb;
	}
	if (nmb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nmb)
	{
		str[len] = nmb % 10 + '0';
		nmb /= 10;
		len--;
	}
	return (str);
}
/*
int	main(void)
{
	long	n = -0;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
