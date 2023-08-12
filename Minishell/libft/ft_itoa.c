/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:00:00 by juduval           #+#    #+#             */
/*   Updated: 2022/11/19 16:41:54 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count = 1;
		n = n * -1;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_min(void)
{
	char	*min;
	char	*nsmin;

	nsmin = NULL;
	min = "-2147483648";
	nsmin = ft_strdup(min);
	return (nsmin);
}

char	*ft_itoa(int n)
{
	char	*ns;
	size_t	i;

	if (n == -2147483648)
		return (ft_min());
	i = ft_count(n);
	ns = malloc((i + 1) * sizeof(char));
	if (!(ns))
		return (0);
	ns[i--] = '\0';
	if (n == 0)
		ns[i] = '0';
	if (n < 0)
	{
		n = n * -1;
		ns[0] = '-';
	}
	while (n > 0)
	{
		ns[i--] = (n % 10) + 48;
		n = n / 10;
	}
	return (ns);
}
/*
int	main(void)
{
	int	n = -2147483648;

	printf("%s\n", ft_itoa(n));
	return (0);
}*/
