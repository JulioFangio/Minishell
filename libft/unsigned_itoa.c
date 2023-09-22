/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:06:04 by jaristil          #+#    #+#             */
/*   Updated: 2023/06/21 19:25:26 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(unsigned int n)
{
	unsigned int	len;

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

char	*unsigned_itoa(unsigned int n)
{
	char	*str;
	int		len;

	len = nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
/*
int	main(void)
{
	unsigned int	n = 11;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
